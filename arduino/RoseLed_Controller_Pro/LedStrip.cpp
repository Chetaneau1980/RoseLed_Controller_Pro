/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : LedStrip
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Gestion complète du panneau de LEDs WS2812B.
 *
 * Ce module assure :
 *  - l'initialisation de FastLED ;
 *  - le rafraîchissement des LEDs ;
 *  - l'allumage et l'extinction ;
 *  - la gestion de la luminosité ;
 *  - la gestion de la couleur fixe ;
 *  - la mémorisation de la dernière couleur sélectionnée.
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

#include "LedStrip.h"
#include "Configuration.h"
#include "Broches.h"
#include "Couleurs.h"

#include <FastLED.h>

//==========================================================
// Tableau des LEDs
//==========================================================

CRGB leds[NOMBRE_LEDS];

//==========================================================
// Variables privées
//==========================================================

namespace
{

// Couleur fixe actuellement sélectionnée.
// Au démarrage, la couleur officielle Octobre Rose est utilisée.
CRGB couleurFixe =
        COULEUR_OCTOBRE_ROSE;

}

//==========================================================
// Initialisation
//==========================================================

void InitialiserLedStrip(void)
{
    FastLED.addLeds<
            WS2812B,
            BROCHE_LED_DATA,
            GRB
    >(
            leds,
            NOMBRE_LEDS
    );

    // Luminosité de sécurité au démarrage.
    FastLED.setBrightness(
            LUMINOSITE_DEFAUT
    );

    // Couleur fixe initiale.
    couleurFixe =
            COULEUR_OCTOBRE_ROSE;

    // Le panneau reste éteint au démarrage.
    FastLED.clear();
    FastLED.show();
}

//==========================================================
// Mise à jour
//==========================================================

void ActualiserLedStrip(void)
{
    FastLED.show();
}

//==========================================================
// Extinction
//==========================================================

void EteindreLedStrip(void)
{
    FastLED.clear();
    FastLED.show();
}

//==========================================================
// Allumage général
//==========================================================

void AllumerLedStrip(void)
{
    couleurFixe =
            COULEUR_OCTOBRE_ROSE;

    fill_solid(
            leds,
            NOMBRE_LEDS,
            couleurFixe
    );

    FastLED.show();
}

//==========================================================
// Luminosité
//==========================================================

void ReglerLuminosite(
        uint8_t luminosite)
{
    FastLED.setBrightness(
            luminosite
    );

    FastLED.show();
}

//==========================================================
// Couleur fixe
//==========================================================

void ReglerCouleur(
        uint8_t rouge,
        uint8_t vert,
        uint8_t bleu)
{
    // Mémorise la couleur sélectionnée.
    couleurFixe =
            CRGB(
                    rouge,
                    vert,
                    bleu
            );

    // Applique immédiatement la couleur.
    fill_solid(
            leds,
            NOMBRE_LEDS,
            couleurFixe
    );

    FastLED.show();
}

//==========================================================
// Lecture de la couleur fixe
//==========================================================

CRGB ObtenirCouleurFixe(void)
{
    return couleurFixe;
}