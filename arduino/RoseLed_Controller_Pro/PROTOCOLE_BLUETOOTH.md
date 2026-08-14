# 🌹 RoseLed Controller Pro Firmware

# Protocole Bluetooth
Version : 0.1
Projet : Octobre Rose

---

# Description

Ce document décrit les commandes Bluetooth utilisées entre
l'application Android et le RoseLed Controller Pro.

Toutes les commandes sont envoyées sous forme de texte ASCII.

Exemple :

RESPIRATION

ou

LUMINOSITE=180

---

# Commandes générales

## Allumer le panneau

ON

---

## Éteindre le panneau

OFF

---

## Couleur officielle Octobre Rose

ROSE

---

## Couleur personnalisée

COULEUR=R,G,B

Exemple

COULEUR=255,20,147

---

# Luminosité

LUMINOSITE=0 à 255

Exemple

LUMINOSITE=180

---

# Vitesse des animations

VITESSE=1 à 100

Exemple

VITESSE=75

---

# Animations

RESPIRATION

BATTEMENT

ARCENCIEL

CHENILLARD

SCINTILLEMENT

FIXE

---

# Informations système

INFO

Réponse du contrôleur

RoseLed Controller Pro Firmware
Version
Carte
État Bluetooth

---

# Réponses

OK

Commande exécutée.

ERREUR

Commande inconnue.

---

# Évolutions futures

Bluetooth Classic

Application Android

Compatibilité WLED

Mise à jour OTA

Sauvegarde automatique des paramètres

---

🌹 RoseLed Controller Pro

Illuminer pour sensibiliser.