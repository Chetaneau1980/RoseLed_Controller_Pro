#ifndef EFFETS_H
#define EFFETS_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Effets
 * Version     : 0.2.1 Alpha
 *
 * Description :
 * Gestion des effets lumineux du RoseLed Controller Pro.
 *
 * Ce module contient les effets élémentaires utilisés
 * par le gestionnaire d'animations.
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

// Initialise le module des effets
void InitialiserEffets(void);

//==========================================================
// Effets lumineux
//==========================================================

// Couleur fixe
void EffetCouleurFixe(void);

// Respiration officielle Octobre Rose
void EffetRespirationRose(void);

// Arc-en-ciel
void EffetArcEnCiel(void);

// Chenillard
void EffetChenillard(void);

// Scintillement
void EffetScintillement(void);

// Battement de cœur
void EffetBattementCoeur(void);

// Vague lumineuse
void EffetVagueRose(void);

// Ruban Octobre Rose
void EffetRubanRose(void);

#endif // EFFETS_H