#ifndef BLUETOOTH_H
#define BLUETOOTH_H

/******************************************************************************
 * RoseLed Controller Pro Firmware
 * ---------------------------------------------------------------------------
 * Module      : Bluetooth
 * Version     : 1.0.0 Alpha
 *
 * Description :
 * Gestion de la communication Bluetooth Classic entre
 * le RoseLed Controller Pro et l'application Android.
 *
 * Ce module assure :
 *  - l'initialisation du Bluetooth Classic ;
 *  - la gestion de la communication ;
 *  - la réception des commandes de l'application Android ;
 *  - l'envoi des informations vers l'application.
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
// Objet Bluetooth
//==========================================================

// Objet Bluetooth Classic global.
extern BluetoothSerial SerialBT;

//==========================================================
// Initialisation
//==========================================================

// Initialise la communication Bluetooth Classic.
void InitialiserBluetooth(void);

//==========================================================
// Gestion Bluetooth
//==========================================================

// Gère la réception et le traitement des communications Bluetooth.
void GererBluetooth(void);

#endif // BLUETOOTH_H