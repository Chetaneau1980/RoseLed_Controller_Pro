# RoseLed Controller Pro — Application Android

Application Android V1.0 permettant de piloter le contrôleur RoseLed par Bluetooth Classic.

## Prérequis

- Android Studio avec JDK 17
- Android SDK 35
- Téléphone Android compatible Bluetooth Classic, Android 6.0 ou supérieur
- Contrôleur préalablement associé sous le nom `RoseLed Controller Pro`

## Ouverture du projet

1. Ouvrir Android Studio.
2. Choisir **Open**.
3. Sélectionner le dossier `Android_App`.
4. Attendre la synchronisation Gradle.
5. Lancer l'application sur un téléphone Android réel.

## Commandes envoyées

- `COLOR #RRGGBB`
- `BRIGHTNESS 0..100`
- `ANIMATION NOM`
- `OFF`

Chaque commande se termine par un caractère LF.

