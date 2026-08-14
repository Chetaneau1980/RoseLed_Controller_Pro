#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * Configuration générale
 *
 * Projet : Octobre Rose
 * Carte : RoseLed Controller Pro Rev.A
 ******************************************************************************/

#include <Arduino.h>

//==========================================================
// Configuration générale
//==========================================================

// Nombre de LEDs WS2812B
constexpr uint16_t NOMBRE_LEDS = 560;

// Luminosité par défaut (0 à 255)
constexpr uint8_t LUMINOSITE_DEFAUT = 150;

// Luminosité maximale
constexpr uint8_t LUMINOSITE_MAX = 255;

// Luminosité minimale
constexpr uint8_t LUMINOSITE_MIN = 10;

// Vitesse par défaut des animations
constexpr uint16_t VITESSE_DEFAUT = 100;

// Nom Bluetooth
constexpr char NOM_BLUETOOTH[] = "RoseLed Controller Pro";

// Version du firmware
constexpr char VERSION[] = "1.0.0 Alpha";

#endif // CONFIGURATION_H