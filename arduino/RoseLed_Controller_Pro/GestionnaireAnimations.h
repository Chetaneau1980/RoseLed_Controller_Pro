#ifndef GESTIONNAIRE_ANIMATIONS_H
#define GESTIONNAIRE_ANIMATIONS_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : GestionnaireAnimations
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Gestionnaire central des animations du RoseLed Controller Pro.
 *
 * Ce module est responsable de :
 *  - mémoriser l'animation actuellement sélectionnée ;
 *  - permettre au Bluetooth de changer d'animation ;
 *  - fournir l'animation active au module Animations.
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
// Liste des animations disponibles
//==========================================================

enum class AnimationActive
{
    ETEINTE = 0,
    FIXE,
    RESPIRATION,
    ARC_EN_CIEL,
    FEU,
    OCEAN,
    FLASH,
    OCTOBRE_ROSE
};

//==========================================================
// Fonctions
//==========================================================

// Initialisation du gestionnaire.
void InitialiserGestionnaireAnimations(void);

// Sélection d'une animation.
void SelectionnerAnimation(AnimationActive animation);

// Retourne l'animation actuellement active.
AnimationActive ObtenirAnimationActive(void);

#endif // GESTIONNAIRE_ANIMATIONS_H