/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : GestionnaireAnimations
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Gestionnaire central des animations du RoseLed Controller Pro.
 *
 * Ce module assure :
 *  - la mémorisation de l'animation sélectionnée ;
 *  - la sélection d'une nouvelle animation ;
 *  - la lecture de l'animation actuellement active.
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

#include "GestionnaireAnimations.h"

//==========================================================
// Variables privées
//==========================================================

// Animation actuellement sélectionnée.
static AnimationActive animationActive = AnimationActive::ETEINTE;

//==========================================================
// Initialisation
//==========================================================

void InitialiserGestionnaireAnimations(void)
{
    animationActive = AnimationActive::ETEINTE;
}

//==========================================================
// Sélection de l'animation
//==========================================================

void SelectionnerAnimation(AnimationActive animation)
{
    animationActive = animation;
}

//==========================================================
// Lecture de l'animation active
//==========================================================

AnimationActive ObtenirAnimationActive(void)
{
    return animationActive;
}