/******************************************************************************
 * RoseLed Controller Pro Firmware
 * Version : 0.2.0 Alpha
 *
 * Projet : Octobre Rose
 * Carte : RoseLed Controller Pro Rev.A
 * Microcontrôleur : ESP32-WROOM-32E
 *
 * Concepteur électronique et développeur :
 * Jérémie
 *
 * Assistance au développement logiciel :
 * ChatGPT (OpenAI)
 *
 * Gestion du bandeau de LEDs WS2812B
 ******************************************************************************/

#include "LedStrip.h"
#include "Configuration.h"
#include "Broches.h"
#include "Couleurs.h"
// Tableau des LEDs
CRGB leds[NOMBRE_LEDS];

//==========================================================
// Initialisation
//==========================================================

void InitialiserLedStrip(void)
{
    // Initialisation de FastLED
    FastLED.addLeds<WS2812B, BROCHE_LED_DATA, GRB>(leds, NOMBRE_LEDS);

    // Luminosité par défaut
    FastLED.setBrightness(LUMINOSITE_DEFAUT);

    // Toutes les LEDs éteintes au démarrage
    FastLED.clear();
    FastLED.show();
}

//==========================================================
// Mise à jour
//==========================================================

void ActualiserLedStrip(void)
{
    FastLED.show();
}

//==========================================================
// Commandes générales
//==========================================================

void EteindreLedStrip(void)
{
    FastLED.clear();
    FastLED.show();
}

void AllumerLedStrip(void)
{
    // Allume toutes les LEDs avec la couleur officielle
    fill_solid(leds, NOMBRE_LEDS, COULEUR_OCTOBRE_ROSE);

    FastLED.show();
}
void ReglerLuminosite(uint8_t luminosite)
{
    FastLED.setBrightness(luminosite);
    FastLED.show();
}

void ReglerCouleur(uint8_t rouge, uint8_t vert, uint8_t bleu)
{
    fill_solid(leds, NOMBRE_LEDS, CRGB(rouge, vert, bleu));
    FastLED.show();
}