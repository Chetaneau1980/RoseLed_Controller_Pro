#ifndef BLUETOOTH_H
#define BLUETOOTH_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Bluetooth
 * Version     : 0.2.1 Alpha
 *
 * Description :
 * Gestion de la communication Bluetooth Classic entre
 * le RoseLed Controller Pro et l'application Android.
 *
 * Ce module assure :
 *  - l'initialisation du Bluetooth ;
 *  - la gestion de la connexion ;
 *  - la réception des commandes ;
 *  - l'envoi des informations au téléphone.
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
#include <BluetoothSerial.h>
//==========================================================
// Initialisation
//==========================================================

// Initialise le Bluetooth
void InitialiserBluetooth(void);

//==========================================================
// Gestion Bluetooth
//==========================================================

// Gestion de la communication Bluetooth
void GererBluetooth(void);
// Objet Bluetooth global
extern BluetoothSerial SerialBT;
#endif // BLUETOOTH_H