/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : System
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Gestion du système principal du RoseLed Controller Pro.
 *
 * Ce module initialise tous les sous-systèmes puis
 * exécute la boucle principale du firmware.
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

#include "System.h"

//==========================================================
// Initialisation du système
//==========================================================

void InitialiserSysteme(void)
{
    // Initialisation des modules du firmware

    InitialiserGestionnaireAnimations();
    InitialiserBluetooth();
    InitialiserLedStrip();
    InitialiserEffets();
    InitialiserAnimations();
}

//==========================================================
// Boucle principale
//==========================================================

void GererSysteme(void)
{
    // Gestion des modules du firmware

    GererBluetooth();
    GererAnimations();
    ActualiserLedStrip();
}