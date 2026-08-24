/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Bluetooth
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Communication Bluetooth Classic entre l'ESP32
 * et l'application Android RoseLed Controller Pro.
 *
 * Commandes compatibles :
 *
 *   STATUS
 *   VERSION
 *   COLOR #RRGGBB
 *   BRIGHTNESS 0..100
 *   ANIMATION Arc-en-ciel
 *   ANIMATION Respiration
 *   ANIMATION Feu
 *   ANIMATION Océan
 *   ANIMATION Flash
 *   ANIMATION Fixe
 *   ANIMATION Octobre Rose
 *   OFF
 *
 * Sécurité :
 *   La luminosité reçue depuis Android est limitée
 *   par LUMINOSITE_MAX défini dans Configuration.h.
 *
 * Projet :
 *   Octobre Rose
 *
 * Carte :
 *   RoseLed Controller Pro Rev.A
 *
 * Microcontrôleur :
 *   ESP32-WROOM-32E
 *
 * Concepteur électronique et développeur :
 *   Jérémie
 *
 * Assistance au développement logiciel :
 *   ChatGPT (OpenAI)
 ******************************************************************************/

#include "Bluetooth.h"
#include "Version.h"
#include "Configuration.h"
#include "LedStrip.h"
#include "GestionnaireAnimations.h"

#include <Arduino.h>

//==========================================================
// Objet Bluetooth
//==========================================================

BluetoothSerial SerialBT;

//==========================================================
// Variables et constantes privées
//==========================================================

namespace
{

constexpr size_t TAILLE_MAX_COMMANDE = 64;

constexpr char REP_CONNECTED[] =
        "CONNECTED";

constexpr char REP_OK[] =
        "OK";

constexpr char REP_ERREUR[] =
        "ERROR";

constexpr char REP_COMMANDE_INCONNUE[] =
        "UNKNOWN_COMMAND";

String commandeRecue;

bool clientConnecte = false;
bool commandeTropLongue = false;

//==========================================================
// Affichage série
//==========================================================

void AfficherInitialisationBluetooth()
{
    Serial.println("--------------------------------");
    Serial.println("Bluetooth initialisé");
    Serial.print("Nom : ");
    Serial.println(NOM_BLUETOOTH);
    Serial.println("--------------------------------");
}

void AfficherCommandeRecue(
        const String& commande)
{
    Serial.print("Commande reçue : ");
    Serial.println(commande);
}

//==========================================================
// Réception
//==========================================================

void ReinitialiserReception()
{
    commandeRecue = "";
    commandeTropLongue = false;
}

void MettreAJourEtatConnexion()
{
    const bool nouvelEtatConnexion =
            SerialBT.hasClient();

    if (nouvelEtatConnexion == clientConnecte)
    {
        return;
    }

    clientConnecte = nouvelEtatConnexion;

    if (clientConnecte)
    {
        Serial.println("Client connecté");
    }
    else
    {
        Serial.println("Client déconnecté");
        ReinitialiserReception();
    }
}

//==========================================================
// Réponses Bluetooth
//==========================================================

void EnvoyerOK()
{
    SerialBT.println(REP_OK);
}

void EnvoyerErreur()
{
    SerialBT.println(REP_ERREUR);
}

//==========================================================
// STATUS
//==========================================================

void TraiterStatus()
{
    SerialBT.println(REP_CONNECTED);
}

//==========================================================
// VERSION
//==========================================================

void TraiterVersion()
{
    SerialBT.println(VERSION_FIRMWARE);
}

//==========================================================
// COLOR #RRGGBB
//==========================================================

bool ConvertirHexadecimal(
        char caractere,
        uint8_t& valeur)
{
    if (caractere >= '0'
            && caractere <= '9')
    {
        valeur =
                static_cast<uint8_t>(
                        caractere - '0'
                );

        return true;
    }

    if (caractere >= 'A'
            && caractere <= 'F')
    {
        valeur =
                static_cast<uint8_t>(
                        caractere - 'A' + 10
                );

        return true;
    }

    if (caractere >= 'a'
            && caractere <= 'f')
    {
        valeur =
                static_cast<uint8_t>(
                        caractere - 'a' + 10
                );

        return true;
    }

    return false;
}

bool ConvertirOctetHexadecimal(
        char caractereHaut,
        char caractereBas,
        uint8_t& valeur)
{
    uint8_t haut = 0;
    uint8_t bas = 0;

    if (!ConvertirHexadecimal(
            caractereHaut,
            haut))
    {
        return false;
    }

    if (!ConvertirHexadecimal(
            caractereBas,
            bas))
    {
        return false;
    }

    valeur =
            static_cast<uint8_t>(
                    (haut << 4) | bas
            );

    return true;
}

void TraiterCouleur(
        const String& parametre)
{
    if (parametre.length() != 7
            || parametre.charAt(0) != '#')
    {
        EnvoyerErreur();
        return;
    }

    uint8_t rouge = 0;
    uint8_t vert = 0;
    uint8_t bleu = 0;

    if (!ConvertirOctetHexadecimal(
            parametre.charAt(1),
            parametre.charAt(2),
            rouge)
            ||
        !ConvertirOctetHexadecimal(
            parametre.charAt(3),
            parametre.charAt(4),
            vert)
            ||
        !ConvertirOctetHexadecimal(
            parametre.charAt(5),
            parametre.charAt(6),
            bleu))
    {
        EnvoyerErreur();
        return;
    }

    ReglerCouleur(
            rouge,
            vert,
            bleu
    );

    EnvoyerOK();
}

//==========================================================
// BRIGHTNESS 0..100
//==========================================================

bool ParametreNumeriqueValide(
        const String& parametre)
{
    if (parametre.length() == 0)
    {
        return false;
    }

    for (size_t i = 0;
         i < parametre.length();
         i++)
    {
        if (!isDigit(parametre.charAt(i)))
        {
            return false;
        }
    }

    return true;
}

void TraiterLuminosite(
        const String& parametre)
{
    if (!ParametreNumeriqueValide(parametre))
    {
        EnvoyerErreur();
        return;
    }

    const int pourcentage =
            parametre.toInt();

    if (pourcentage < 0
            || pourcentage > 100)
    {
        EnvoyerErreur();
        return;
    }

    /*
     * Android travaille de 0 à 100 %.
     *
     * Le firmware ne convertit volontairement PAS
     * directement vers 255.
     *
     * Exemple avec LUMINOSITE_MAX = 80 :
     *
     * Android 0 %   -> FastLED 0
     * Android 50 %  -> FastLED 40
     * Android 100 % -> FastLED 80
     *
     * Impossible donc de dépasser la limite définie
     * dans Configuration.h.
     */

    const uint8_t luminosite =
            static_cast<uint8_t>(
                    map(
                            pourcentage,
                            0,
                            100,
                            0,
                            LUMINOSITE_MAX
                    )
            );

    ReglerLuminosite(
            luminosite
    );

    EnvoyerOK();
}

//==========================================================
// ANIMATION
//==========================================================

bool SelectionnerAnimationDepuisNom(
        const String& nomAnimation)
{
    if (nomAnimation == "Arc-en-ciel")
    {
        SelectionnerAnimation(
                AnimationActive::ARC_EN_CIEL
        );

        return true;
    }

    if (nomAnimation == "Respiration")
    {
        SelectionnerAnimation(
                AnimationActive::RESPIRATION
        );

        return true;
    }

    if (nomAnimation == "Feu")
    {
        SelectionnerAnimation(
                AnimationActive::FEU
        );

        return true;
    }

    if (nomAnimation == "Océan"
            || nomAnimation == "Ocean")
    {
        SelectionnerAnimation(
                AnimationActive::OCEAN
        );

        return true;
    }

    if (nomAnimation == "Flash")
    {
        SelectionnerAnimation(
                AnimationActive::FLASH
        );

        return true;
    }

    if (nomAnimation == "Fixe")
    {
        SelectionnerAnimation(
                AnimationActive::FIXE
        );

        return true;
    }

    if (nomAnimation == "Octobre Rose")
    {
        SelectionnerAnimation(
                AnimationActive::OCTOBRE_ROSE
        );

        return true;
    }

    return false;
}

void TraiterAnimation(
        const String& parametre)
{
    if (!SelectionnerAnimationDepuisNom(
            parametre))
    {
        EnvoyerErreur();
        return;
    }

    EnvoyerOK();
}

//==========================================================
// OFF
//==========================================================

void TraiterExtinction()
{
    SelectionnerAnimation(
            AnimationActive::ETEINTE
    );

    EteindreLedStrip();

    EnvoyerOK();
}

//==========================================================
// Analyse générale d'une commande
//==========================================================

void TraiterCommande(
        const String& commandeComplete)
{
    AfficherCommandeRecue(
            commandeComplete
    );

    String nomCommande;
    String parametre;

    const int positionEspace =
            commandeComplete.indexOf(' ');

    if (positionEspace < 0)
    {
        nomCommande =
                commandeComplete;

        parametre = "";
    }
    else
    {
        nomCommande =
                commandeComplete.substring(
                        0,
                        positionEspace
                );

        parametre =
                commandeComplete.substring(
                        positionEspace + 1
                );

        parametre.trim();
    }

    nomCommande.trim();
    nomCommande.toUpperCase();

    if (nomCommande == "STATUS")
    {
        TraiterStatus();
        return;
    }

    if (nomCommande == "VERSION")
    {
        TraiterVersion();
        return;
    }

    if (nomCommande == "COLOR")
    {
        TraiterCouleur(
                parametre
        );

        return;
    }

    if (nomCommande == "BRIGHTNESS")
    {
        TraiterLuminosite(
                parametre
        );

        return;
    }

    if (nomCommande == "ANIMATION")
    {
        TraiterAnimation(
                parametre
        );

        return;
    }

    if (nomCommande == "OFF")
    {
        TraiterExtinction();
        return;
    }

    Serial.println(
            "Commande inconnue"
    );

    SerialBT.println(
            REP_COMMANDE_INCONNUE
    );
}

//==========================================================
// Fin de commande
//==========================================================

void FinaliserCommande()
{
    if (commandeTropLongue)
    {
        ReinitialiserReception();
        return;
    }

    commandeRecue.trim();

    if (commandeRecue.length() > 0)
    {
        TraiterCommande(
                commandeRecue
        );
    }

    commandeRecue = "";
}

//==========================================================
// Ajout d'un caractère
//==========================================================

void AjouterCaractere(
        char caractereRecu)
{
    if (caractereRecu == '\n')
    {
        FinaliserCommande();
        return;
    }

    if (caractereRecu == '\r')
    {
        return;
    }

    if (commandeTropLongue)
    {
        return;
    }

    if (commandeRecue.length()
            >= TAILLE_MAX_COMMANDE)
    {
        commandeRecue = "";
        commandeTropLongue = true;

        return;
    }

    commandeRecue += caractereRecu;
}

//==========================================================
// Lecture Bluetooth
//==========================================================

void LireCommandesBluetooth()
{
    while (SerialBT.available() > 0)
    {
        AjouterCaractere(
                static_cast<char>(
                        SerialBT.read()
                )
        );
    }
}

} // namespace

//==========================================================
// Initialisation publique
//==========================================================

void InitialiserBluetooth()
{
    commandeRecue.reserve(
            TAILLE_MAX_COMMANDE
    );

    SerialBT.begin(
            NOM_BLUETOOTH
    );

    clientConnecte =
            SerialBT.hasClient();

    AfficherInitialisationBluetooth();
}

//==========================================================
// Gestion publique
//==========================================================

void GererBluetooth()
{
    MettreAJourEtatConnexion();

    if (!clientConnecte)
    {
        return;
    }

    LireCommandesBluetooth();
}