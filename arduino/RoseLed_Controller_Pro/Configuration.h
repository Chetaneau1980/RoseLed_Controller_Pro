#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Configuration
 * Version     : 0.3.1 Alpha
 *
 * Description :
 * Configuration générale du RoseLed Controller Pro.
 *
 * Les limites de luminosité sont volontairement prudentes
 * afin de protéger le panneau, son câblage et l'alimentation.
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

//==========================================================
// LEDs WS2812B
//==========================================================

// Nombre total de LEDs du panneau.
constexpr uint16_t NOMBRE_LEDS = 560;

//==========================================================
// Luminosité
//==========================================================

/*
 * FastLED utilise une échelle de 0 à 255.
 *
 * Pour les premiers essais :
 *
 * 50 / 255 ≈ 20 % au démarrage
 * 80 / 255 ≈ 31 % maximum
 *
 * Cette limite pourra être réévaluée après les essais
 * réels de tension, courant et température.
 */

// Luminosité appliquée au démarrage.
constexpr uint8_t LUMINOSITE_DEFAUT = 50;

// Limite maximale autorisée par le firmware.
constexpr uint8_t LUMINOSITE_MAX = 80;

// Luminosité minimale utile.
// La valeur 0 reste autorisée pour l'extinction.
constexpr uint8_t LUMINOSITE_MIN = 10;

//==========================================================
// Animations
//==========================================================

// Vitesse par défaut des animations.
constexpr uint16_t VITESSE_DEFAUT = 100;

//==========================================================
// Bluetooth
//==========================================================

// Nom visible depuis l'application Android.
constexpr char NOM_BLUETOOTH[] =
        "RoseLed Controller Pro";

#endif // CONFIGURATION_H