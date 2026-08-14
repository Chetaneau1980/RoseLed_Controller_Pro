#ifndef COULEURS_H
#define COULEURS_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * Version : 0.2.1 Alpha
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
 * Palette officielle des couleurs
 ******************************************************************************/

#include <FastLED.h>

//==========================================================
// Couleurs officielles Octobre Rose
//==========================================================

constexpr CRGB COULEUR_OCTOBRE_ROSE = CRGB(255, 20, 147);
constexpr CRGB COULEUR_ROSE_CLAIR   = CRGB(255, 105, 180);
constexpr CRGB COULEUR_ROSE_DOUX    = CRGB(255, 182, 193);
constexpr CRGB COULEUR_FUCHSIA      = CRGB(255, 0, 255);

//==========================================================
// Couleurs standards
//==========================================================

constexpr CRGB COULEUR_ROUGE   = CRGB::Red;
constexpr CRGB COULEUR_VERT    = CRGB::Green;
constexpr CRGB COULEUR_BLEU    = CRGB::Blue;
constexpr CRGB COULEUR_BLANC   = CRGB::White;
constexpr CRGB COULEUR_NOIR    = CRGB::Black;
constexpr CRGB COULEUR_JAUNE   = CRGB::Yellow;
constexpr CRGB COULEUR_ORANGE  = CRGB::Orange;
constexpr CRGB COULEUR_VIOLET  = CRGB::Purple;
constexpr CRGB COULEUR_CYAN    = CRGB::Cyan;

//==========================================================
// Couleurs techniques
//==========================================================

constexpr CRGB COULEUR_ERREUR  = CRGB::Red;
constexpr CRGB COULEUR_OK      = CRGB::Green;
constexpr CRGB COULEUR_ATTENTE = CRGB::Orange;

#endif // COULEURS_H