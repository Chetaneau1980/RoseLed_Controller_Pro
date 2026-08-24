#ifndef BROCHES_H
#define BROCHES_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Broches
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Définition centralisée des broches utilisées par
 * le RoseLed Controller Pro.
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
// Boutons
//==========================================================

// SW1 : bouton RESET.
// Relié directement à la broche EN de l'ESP32.
// Cette broche n'est pas pilotable par le firmware.
constexpr const char* BROCHE_RESET = "EN";

// SW2 : bouton BOOT.
constexpr uint8_t BROCHE_BOOT = 0;

//==========================================================
// LEDs WS2812B
//==========================================================

// Signal DATA vers le buffer logique 74AHCT1G125.
constexpr uint8_t BROCHE_LED_DATA = 23;

#endif // BROCHES_H