/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Fichier principal
 *
 * Projet :
 *   Octobre Rose
 *
 * Carte :
 *   RoseLed Controller Pro Rev.A
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

void setup()
{
    // Initialisation de la liaison série
    Serial.begin(115200);

    // Petite attente
    delay(1000);

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
    Serial.println("Firmware initialisé.");
    Serial.println();

    // Initialisation complète du firmware
    InitialiserSysteme();
}

void loop()
{
    // Gestion du firmware
    GererSysteme();
}