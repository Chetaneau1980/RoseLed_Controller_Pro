/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Animations
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Gestion des animations lumineuses du panneau WS2812B.
 *
 * Ce module assure :
 *  - l'exécution de l'animation actuellement sélectionnée ;
 *  - l'appel des effets lumineux correspondants ;
 *  - le retour à l'état éteint en cas d'état inconnu.
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

#include "Animations.h"
#include "Effets.h"
#include "GestionnaireAnimations.h"
#include "LedStrip.h"

//==========================================================
// Initialisation
//==========================================================

void InitialiserAnimations(void)
{
    // Les animations démarrent dans l'état défini
    // par le GestionnaireAnimations.
}

//==========================================================
// Gestion des animations
//==========================================================

void GererAnimations(void)
{
    switch (ObtenirAnimationActive())
    {
        case AnimationActive::ETEINTE:
            AnimationEteinte();
            break;

        case AnimationActive::FIXE:
            AnimationFixe();
            break;

        case AnimationActive::RESPIRATION:
            AnimationRespiration();
            break;

        case AnimationActive::ARC_EN_CIEL:
            AnimationArcEnCiel();
            break;

        case AnimationActive::FEU:
            AnimationFeu();
            break;

        case AnimationActive::OCEAN:
            AnimationOcean();
            break;

        case AnimationActive::FLASH:
            AnimationFlash();
            break;

        case AnimationActive::OCTOBRE_ROSE:
            AnimationOctobreRose();
            break;

        default:
            AnimationEteinte();
            break;
    }
}

//==========================================================
// Animations disponibles
//==========================================================

void AnimationEteinte(void)
{
    EteindreLedStrip();
}

void AnimationFixe(void)
{
    EffetCouleurFixe();
}

void AnimationRespiration(void)
{
    EffetRespirationRose();
}

void AnimationArcEnCiel(void)
{
    EffetArcEnCiel();
}

void AnimationFeu(void)
{
    EffetFeu();
}

void AnimationOcean(void)
{
    EffetOcean();
}

void AnimationFlash(void)
{
    EffetFlash();
}

void AnimationOctobreRose(void)
{
    EffetOctobreRose();
}