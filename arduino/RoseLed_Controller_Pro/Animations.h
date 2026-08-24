#ifndef ANIMATIONS_H
#define ANIMATIONS_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Animations
 * Version     : 0.3.0 Alpha
 *
 * Description :
 * Gestion complète des animations lumineuses du panneau WS2812B.
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

void InitialiserAnimations(void);

//==========================================================
// Gestion des animations
//==========================================================

void GererAnimations(void);

//==========================================================
// Animations disponibles
//==========================================================

// Panneau éteint
void AnimationEteinte(void);

// Couleur fixe
void AnimationFixe(void);

// Respiration
void AnimationRespiration(void);

// Arc-en-ciel
void AnimationArcEnCiel(void);

// Feu
void AnimationFeu(void);

// Océan
void AnimationOcean(void);

// Flash
void AnimationFlash(void);

// Animation officielle Octobre Rose
void AnimationOctobreRose(void);

#endif // ANIMATIONS_H