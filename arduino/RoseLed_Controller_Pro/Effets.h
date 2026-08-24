#ifndef EFFETS_H
#define EFFETS_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Effets
 * Version     : 0.3.0 Alpha
 *
 * Description :
 * Gestion des effets lumineux du RoseLed Controller Pro.
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
// Initialisation
//==========================================================

void InitialiserEffets(void);

//==========================================================
// Effets lumineux
//==========================================================

// Couleur fixe
void EffetCouleurFixe(void);

// Respiration rose
void EffetRespirationRose(void);

// Arc-en-ciel
void EffetArcEnCiel(void);

// Feu
void EffetFeu(void);

// Océan
void EffetOcean(void);

// Flash
void EffetFlash(void);

// Animation officielle Octobre Rose
void EffetOctobreRose(void);

#endif // EFFETS_H