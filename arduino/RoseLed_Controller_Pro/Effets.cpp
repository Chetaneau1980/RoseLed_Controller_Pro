/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Effets
 * Version     : 0.3.2 Alpha
 *
 * Description :
 * Effets lumineux du RoseLed Controller Pro.
 *
 * Les effets sont non bloquants afin de conserver
 * une communication Bluetooth réactive.
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

#include "Effets.h"
#include "LedStrip.h"
#include "Configuration.h"
#include "Couleurs.h"

#include <FastLED.h>

//==========================================================
// Variables internes
//==========================================================

namespace
{
    unsigned long dernierRafraichissement = 0;

    uint8_t phaseRespiration = 0;
    bool respirationMonte = true;

    uint8_t teinteArcEnCiel = 0;

    uint8_t phaseOcean = 0;

    bool etatFlash = false;

    uint16_t positionOctobreRose = 0;

    constexpr uint16_t INTERVALLE_RESPIRATION = 20;
    constexpr uint16_t INTERVALLE_ARC_EN_CIEL = 25;
    constexpr uint16_t INTERVALLE_FEU = 45;
    constexpr uint16_t INTERVALLE_OCEAN = 35;
    constexpr uint16_t INTERVALLE_FLASH = 250;
    constexpr uint16_t INTERVALLE_OCTOBRE_ROSE = 35;
}

//==========================================================
// Initialisation
//==========================================================

void InitialiserEffets(void)
{
    dernierRafraichissement = 0;

    phaseRespiration = 0;
    respirationMonte = true;

    teinteArcEnCiel = 0;
    phaseOcean = 0;

    etatFlash = false;
    positionOctobreRose = 0;
}

//==========================================================
// Couleur fixe
//==========================================================

void EffetCouleurFixe(void)
{
    const CRGB couleurFixe =
            ObtenirCouleurFixe();

    fill_solid(
        leds,
        NOMBRE_LEDS,
        couleurFixe
    );
}

//==========================================================
// Respiration rose
//==========================================================

void EffetRespirationRose(void)
{
    const unsigned long maintenant = millis();

    if (maintenant - dernierRafraichissement
            < INTERVALLE_RESPIRATION)
    {
        return;
    }

    dernierRafraichissement = maintenant;

    if (respirationMonte)
    {
        if (phaseRespiration < 250)
        {
            phaseRespiration += 5;
        }
        else
        {
            respirationMonte = false;
        }
    }
    else
    {
        if (phaseRespiration > 20)
        {
            phaseRespiration -= 5;
        }
        else
        {
            respirationMonte = true;
        }
    }

    CRGB couleur =
            COULEUR_OCTOBRE_ROSE;

    couleur.nscale8_video(
        phaseRespiration
    );

    fill_solid(
        leds,
        NOMBRE_LEDS,
        couleur
    );
}

//==========================================================
// Arc-en-ciel
//==========================================================

void EffetArcEnCiel(void)
{
    const unsigned long maintenant = millis();

    if (maintenant - dernierRafraichissement
            < INTERVALLE_ARC_EN_CIEL)
    {
        return;
    }

    dernierRafraichissement = maintenant;

    fill_rainbow(
        leds,
        NOMBRE_LEDS,
        teinteArcEnCiel,
        4
    );

    teinteArcEnCiel++;
}

//==========================================================
// Feu
//==========================================================

void EffetFeu(void)
{
    const unsigned long maintenant = millis();

    if (maintenant - dernierRafraichissement
            < INTERVALLE_FEU)
    {
        return;
    }

    dernierRafraichissement = maintenant;

    for (uint16_t i = 0;
         i < NOMBRE_LEDS;
         i++)
    {
        const uint8_t chaleur =
                random8(120, 255);

        leds[i] =
                ColorFromPalette(
                    HeatColors_p,
                    chaleur
                );
    }
}

//==========================================================
// Océan
//==========================================================

void EffetOcean(void)
{
    const unsigned long maintenant = millis();

    if (maintenant - dernierRafraichissement
            < INTERVALLE_OCEAN)
    {
        return;
    }

    dernierRafraichissement = maintenant;

    for (uint16_t i = 0;
         i < NOMBRE_LEDS;
         i++)
    {
        const uint8_t vague =
                sin8(
                    (i * 4)
                    + phaseOcean
                );

        leds[i] =
                ColorFromPalette(
                    OceanColors_p,
                    vague
                );
    }

    phaseOcean += 2;
}

//==========================================================
// Flash
//==========================================================

void EffetFlash(void)
{
    const unsigned long maintenant = millis();

    if (maintenant - dernierRafraichissement
            < INTERVALLE_FLASH)
    {
        return;
    }

    dernierRafraichissement = maintenant;

    etatFlash = !etatFlash;

    if (etatFlash)
    {
        fill_solid(
            leds,
            NOMBRE_LEDS,
            COULEUR_OCTOBRE_ROSE
        );
    }
    else
    {
        fill_solid(
            leds,
            NOMBRE_LEDS,
            CRGB::Black
        );
    }
}

//==========================================================
// Animation officielle Octobre Rose
//==========================================================

void EffetOctobreRose(void)
{
    const unsigned long maintenant = millis();

    if (maintenant - dernierRafraichissement
            < INTERVALLE_OCTOBRE_ROSE)
    {
        return;
    }

    dernierRafraichissement = maintenant;

    fadeToBlackBy(
        leds,
        NOMBRE_LEDS,
        25
    );

    leds[positionOctobreRose] =
            COULEUR_OCTOBRE_ROSE;

    positionOctobreRose++;

    if (positionOctobreRose >= NOMBRE_LEDS)
    {
        positionOctobreRose = 0;
    }
}