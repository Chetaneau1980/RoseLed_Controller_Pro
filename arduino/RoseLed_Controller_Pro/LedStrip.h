#ifndef LEDSTRIP_H
#define LEDSTRIP_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : LedStrip
 * Version     : 0.2.1 Alpha
 *
 * Description :
 * Gestion complète du bandeau de LEDs WS2812B.
 *
 * Ce module assure :
 *  - l'initialisation de FastLED ;
 *  - le rafraîchissement du bandeau ;
 *  - l'allumage et l'extinction des LEDs ;
 *  - la gestion de la luminosité ;
 *  - la gestion des couleurs.
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

#ifndef ARDUINO_H
#include <Arduino.h>
#endif

#include <FastLED.h>

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

// Éteint toutes les LEDs
void EteindreLedStrip(void);

// Allume toutes les LEDs avec la couleur officielle
void AllumerLedStrip(void);

// Modifie la luminosité générale
void ReglerLuminosite(uint8_t luminosite);

// Modifie la couleur de toutes les LEDs
void ReglerCouleur(uint8_t rouge, uint8_t vert, uint8_t bleu);

#endif // LEDSTRIP_H