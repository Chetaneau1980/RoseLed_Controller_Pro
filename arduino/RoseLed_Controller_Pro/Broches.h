#ifndef BROCHES_H
#define BROCHES_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * Définition des broches
 *
 * Projet : Octobre Rose
 * Carte : RoseLed Controller Pro Rev.A
 ******************************************************************************/

#include <Arduino.h>

//==========================================================
// Boutons
//==========================================================

// SW1 : Bouton RESET (broche EN de l'ESP32 - non pilotable par logiciel)
constexpr const char* BROCHE_RESET = "EN";

// SW2 : Bouton BOOT
constexpr uint8_t BROCHE_BOOT = 0;

//==========================================================
// LEDs WS2812B
//==========================================================

// Signal DATA vers le 74AHCT1G125
constexpr uint8_t BROCHE_LED_DATA = 23;

#endif // BROCHES_H