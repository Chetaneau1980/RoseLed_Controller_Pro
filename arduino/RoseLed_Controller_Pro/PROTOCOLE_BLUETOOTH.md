# 🌹 RoseLed Controller Pro

# Protocole Bluetooth

**Version du firmware : 1.0.0 Alpha**  
**Projet : Octobre Rose**

---

## Description

Ce document décrit le protocole de communication Bluetooth Classic utilisé entre l'application Android et le firmware du RoseLed Controller Pro.

La communication utilise le Bluetooth Classic SPP.

Les commandes sont envoyées sous forme de texte et doivent être terminées par un retour à la ligne.

---

## Format général

Certaines commandes ne nécessitent aucun paramètre :

STATUS

VERSION

OFF

D'autres utilisent le format :

COMMANDE PARAMETRE

Exemple :

BRIGHTNESS 50

ou :

COLOR #FF1493

---

# Commandes disponibles

## STATUS

Vérifie la communication avec le contrôleur.

Commande :

STATUS

Réponse :

CONNECTED

---

## VERSION

Demande la version du firmware installée sur l'ESP32.

Commande :

VERSION

Réponse actuelle :

1.0.0 Alpha

---

## COLOR

Permet de sélectionner une couleur fixe.

Format :

COLOR #RRGGBB

Exemple pour la couleur Octobre Rose :

COLOR #FF1493

Le format RGB utilise une notation hexadécimale.

Après réception d'une couleur valide, le contrôleur répond :

OK

En cas de valeur incorrecte :

ERROR

---

## BRIGHTNESS

Permet de régler la luminosité depuis l'application Android.

Format :

BRIGHTNESS 0..100

Exemples :

BRIGHTNESS 0

BRIGHTNESS 50

BRIGHTNESS 100

La valeur envoyée par Android est exprimée en pourcentage.

Le firmware applique ensuite automatiquement la limite de sécurité définie par :

LUMINOSITE_MAX

dans le fichier :

Configuration.h

Ainsi, une commande `BRIGHTNESS 100` ne permet pas de dépasser la limite maximale autorisée par le firmware.

Réponse :

OK

ou :

ERROR

---

# Animations

La sélection d'une animation utilise le format :

ANIMATION Nom

## Arc-en-ciel

ANIMATION Arc-en-ciel

## Respiration

ANIMATION Respiration

## Feu

ANIMATION Feu

## Océan

ANIMATION Océan

La variante suivante est également acceptée :

ANIMATION Ocean

## Flash

ANIMATION Flash

## Couleur fixe

ANIMATION Fixe

## Octobre Rose

ANIMATION Octobre Rose

Après sélection d'une animation valide :

OK

Si le nom de l'animation n'est pas reconnu :

ERROR

---

# Extinction

## OFF

Éteint le panneau et sélectionne l'état `ETEINTE`.

Commande :

OFF

Réponse :

OK

---

# Réponses du contrôleur

Le contrôleur peut envoyer les réponses suivantes :

## CONNECTED

La communication avec le contrôleur est active.

## OK

La commande a été reconnue et exécutée.

## ERROR

La commande a été reconnue mais son paramètre est invalide.

## UNKNOWN_COMMAND

La commande envoyée n'est pas reconnue par le firmware.

---

# Limite des commandes

La taille maximale d'une commande reçue est limitée par le firmware.

Les commandes doivent rester courtes et respecter exactement le protocole défini dans ce document.

---

# Architecture de communication

Application Android

↓

Bluetooth Classic SPP

↓

ESP32-WROOM-32E

↓

RoseLed Controller Pro

↓

FastLED

↓

LEDs WS2812B

---

# Compatibilité actuelle

- ESP32-WROOM-32E
- Bluetooth Classic SPP
- Application Android RoseLed Controller Pro
- FastLED
- LEDs WS2812B

---

# Évolutions futures

Les fonctionnalités futures éventuelles doivent rester distinctes du protocole actuellement implémenté.

Toute nouvelle commande Bluetooth devra être ajoutée :

1. au firmware ;
2. à l'application Android ;
3. à ce document.

---

## ❤️ RoseLed Controller Pro

**Développé par Jérémie**

Assistance au développement logiciel : **ChatGPT (OpenAI)**

**Projet Octobre Rose**

🌹 *Illuminer pour sensibiliser.*