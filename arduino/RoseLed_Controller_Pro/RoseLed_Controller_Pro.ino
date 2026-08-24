/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Fichier     : RoseLed_Controller_Pro.ino
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Point d'entrée principal du firmware RoseLed Controller Pro.
 *
 * Ce fichier assure :
 *  - l'initialisation de la liaison série ;
 *  - l'affichage des informations du firmware au démarrage ;
 *  - l'initialisation générale du système ;
 *  - l'exécution de la boucle principale.
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

#include <Arduino.h>

#include "Version.h"
#include "System.h"

//==========================================================
// Initialisation principale
//==========================================================

void setup()
{
    // Initialisation de la liaison série.
    Serial.begin(115200);

    // Petite attente afin de stabiliser le démarrage.
    delay(1000);

    // Affichage des informations du firmware.
    Serial.println();
    Serial.println("========================================");
    Serial.println(NOM_FIRMWARE);

    Serial.print("Version : ");
    Serial.println(VERSION_FIRMWARE);

    Serial.print("Concepteur : ");
    Serial.println(CONCEPTEUR);

    Serial.print("Projet : ");
    Serial.println(PROJET);

    Serial.print("Carte : ");
    Serial.println(CARTE);

    Serial.print("Microcontrôleur : ");
    Serial.println(MICROCONTROLEUR);

    Serial.println("========================================");

    // Initialisation complète du firmware.
    InitialiserSysteme();

    Serial.println("Firmware initialisé.");
    Serial.println();
}

//==========================================================
// Boucle principale
//==========================================================

void loop()
{
    // Gestion générale du firmware.
    GererSysteme();
}