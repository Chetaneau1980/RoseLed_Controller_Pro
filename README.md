<div align="center">

# 🌹 RoseLed Controller Pro

### Professional ESP32 WS2812B LED Controller
### Projet Open Source — Octobre Rose

[![Version](https://img.shields.io/badge/version-1.0.0%20Alpha-ff1493?style=for-the-badge)](https://github.com/)
[![ESP32](https://img.shields.io/badge/ESP32-WROOM--32E-000000?style=for-the-badge&logo=espressif)](https://www.espressif.com/)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=for-the-badge&logo=arduino)](https://www.arduino.cc/)
[![Bluetooth](https://img.shields.io/badge/Bluetooth-Classic-0082FC?style=for-the-badge&logo=bluetooth)](https://www.bluetooth.com/)
[![FastLED](https://img.shields.io/badge/FastLED-WS2812B-ff1493?style=for-the-badge)](https://fastled.io/)
[![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)](LICENSE)

**Un contrôleur ESP32 conçu pour piloter un panneau de 560 LEDs WS2812B
depuis une application Android via Bluetooth Classic.**

🌹 **Illuminer pour sensibiliser.**

</div>

---

# 🌹 Présentation

**RoseLed Controller Pro** est un projet Open Source dédié au pilotage
d'un panneau lumineux **Octobre Rose** équipé de **560 LEDs WS2812B**.

Le système repose sur un **ESP32-WROOM-32E** et une architecture firmware
modulaire conçue pour privilégier :

- la simplicité ;
- la stabilité ;
- la lisibilité du code ;
- la maintenance ;
- l'évolution future du projet.

Le contrôleur communique avec une **application Android dédiée** grâce au
**Bluetooth Classic**.

---

# ✨ Fonctionnalités

| Fonction | État |
|---|:---:|
| 🌹 Animation Octobre Rose | ✅ |
| 🎨 Couleur fixe | ✅ |
| 🌈 Arc-en-ciel | ✅ |
| 🌬️ Respiration rose | ✅ |
| 🔥 Effet Feu | ✅ |
| 🌊 Effet Océan | ✅ |
| ⚡ Effet Flash | ✅ |
| 💡 Gestion de luminosité | ✅ |
| 🛡️ Limitation de luminosité | ✅ |
| 📶 Bluetooth Classic | ✅ |
| 📱 Application Android | 🚧 |
| 💾 Mémorisation des paramètres | 🚧 |
| 🌐 Compatibilité WLED | 🚧 |
| 🔄 OTA | 🚧 |

---

# 🔥 Matériel

### Contrôleur

- **ESP32-WROOM-32E**
- Carte : **RoseLed Controller Pro Rev.A**
- Bluetooth Classic
- Sortie DATA WS2812B
- Niveau logique adapté via **74AHCT1G125**

### Éclairage

- **560 × WS2812B**
- Alimentation : **5 V**
- Signal : **GRB**
- Données sur **GPIO 23**

### Sécurité

La luminosité maximale est volontairement limitée par le firmware.

Configuration actuelle :

```text
Luminosité par défaut : 50 / 255
Luminosité maximale    : 80 / 255
Luminosité minimale    : 10 / 255