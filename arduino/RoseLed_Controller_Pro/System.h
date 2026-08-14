#ifndef SYSTEM_H
#define SYSTEM_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : System
 * Version     : 0.2.1 Alpha
 *
 * Description :
 * Gestion du système principal du RoseLed Controller Pro.
 *
 * Ce module assure :
 *  - l'initialisation complète du firmware ;
 *  - la gestion de la boucle principale ;
 *  - la coordination des différents modules.
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
// Modules du firmware
//==========================================================

#include "Configuration.h"
#include "Broches.h"
#include "Couleurs.h"
#include "LedStrip.h"
#include "Effets.h"
#include "Animations.h"
#include "GestionnaireAnimations.h"
#include "Bluetooth.h"

//==========================================================
// Gestion du système
//==========================================================

// Initialisation complète du firmware
void InitialiserSysteme(void);

// Boucle principale du firmware
void GererSysteme(void);

#endif // SYSTEM_H