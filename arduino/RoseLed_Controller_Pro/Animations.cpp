/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Animations
 * Version     : 0.2.1 Alpha
 *
 * Description :
 * Gestion des animations lumineuses du panneau WS2812B.
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
    // Initialisation des animations
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

        case AnimationActive::CHENILLARD:
            AnimationChenillard();
            break;

        case AnimationActive::SCINTILLEMENT:
            AnimationScintillement();
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

void AnimationChenillard(void)
{
    EffetChenillard();
}

void AnimationScintillement(void)
{
    EffetScintillement();
}