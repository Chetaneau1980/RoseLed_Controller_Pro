#ifndef LEDSTRIP_H
#define LEDSTRIP_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : LedStrip
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Gestion complète du bandeau de LEDs WS2812B.
 *
 * Ce module assure :
 *  - l'initialisation de FastLED ;
 *  - le rafraîchissement du bandeau ;
 *  - l'allumage et l'extinction des LEDs ;
 *  - la gestion de la luminosité ;
 *  - la gestion des couleurs ;
 *  - la mémorisation de la couleur fixe.
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
#include <FastLED.h>

#include "Configuration.h"

//==========================================================
// Tableau des LEDs
//==========================================================

extern CRGB leds[NOMBRE_LEDS];

//==========================================================
// Initialisation
//==========================================================

void InitialiserLedStrip(void);

//==========================================================
// Rafraîchissement
//==========================================================

void ActualiserLedStrip(void);

//==========================================================
// Commandes générales
//==========================================================

void EteindreLedStrip(void);

void AllumerLedStrip(void);

void ReglerLuminosite(
    uint8_t luminosite
);

void ReglerCouleur(
    uint8_t rouge,
    uint8_t vert,
    uint8_t bleu
);

//==========================================================
// Couleur fixe mémorisée
//==========================================================

CRGB ObtenirCouleurFixe(void);

#endif // LEDSTRIP_H