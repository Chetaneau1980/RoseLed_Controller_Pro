#ifndef VERSION_H
#define VERSION_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Version
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Informations générales et identification du firmware
 * RoseLed Controller Pro.
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
// Informations du firmware
//==========================================================

constexpr const char NOM_FIRMWARE[] =
        "RoseLed Controller Pro";

constexpr const char VERSION_FIRMWARE[] =
        "1.0.0 Alpha";

constexpr const char CONCEPTEUR[] =
        "Jeremie";

constexpr const char PROJET[] =
        "Octobre Rose";

constexpr const char CARTE[] =
        "RoseLed Controller Pro Rev.A";

constexpr const char MICROCONTROLEUR[] =
        "ESP32-WROOM-32E";

constexpr const char ANNEE[] =
        "2026";

#endif // VERSION_H