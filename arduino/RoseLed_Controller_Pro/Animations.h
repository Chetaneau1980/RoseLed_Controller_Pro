#ifndef ANIMATIONS_H
#define ANIMATIONS_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Animations
 * Version     : 0.2.1 Alpha
 *
 * Description :
 * Gestion complète des animations lumineuses du panneau WS2812B.
 *
 * Ce module assure :
 *  - l'initialisation des animations ;
 *  - la gestion de l'animation active ;
 *  - l'exécution des effets lumineux ;
 *  - les futures commandes Bluetooth ;
 *  - la compatibilité avec le mode WLED.
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

#ifndef ARDUINO_H
#include <Arduino.h>
#endif

//==========================================================
// Initialisation
//==========================================================

void InitialiserAnimations(void);

//==========================================================
// Gestion des animations
//==========================================================

// Gestion de l'animation en cours
void GererAnimations(void);

//==========================================================
// Animations disponibles
//==========================================================

// Panneau éteint
void AnimationEteinte(void);

// Couleur fixe
void AnimationFixe(void);

// Animation officielle Octobre Rose
void AnimationRespiration(void);

// Animation Arc-en-ciel
void AnimationArcEnCiel(void);

// Animation Chenillard
void AnimationChenillard(void);

// Animation Scintillement
void AnimationScintillement(void);

#endif // ANIMATIONS_H