/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : GestionnaireAnimations
 * Version     : 0.2.1 Alpha
 *
 * Description :
 * Gestionnaire central des animations.
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

// Animation actuellement sélectionnée
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