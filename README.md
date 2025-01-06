# Projet_Lora
Code source Projet ECG et TTN

Guide d'installation et de configuration

Étape 1 : Création d'une application TTN
- Installez la version 1.8.9 de l'IDE Arduino pour une compatibilité optimale.
- Lancer le script DeviceInfo.ino afin d'avoir accès aux informations nécessaires (AppEUI,DevId) : https://www.npackd.org/p/ArduinoSA.arduino/1.8.9
- Connectez-vous à The Things Network (TTN).
- Créez une nouvelle application dans la console TTN.
- Ajoutez votre end device à l'application créée
- Ajouter le contenu du fichier Payload_TTN dans le payload formater de votre end device.

Étape 2 : Configuration de l'Arduino UNO
- Téléchargez et ouvrez le fichier Generateur_EG_A_JOUR.ino dans l'IDE Arduino.
- Sélectionnez le bon port COM correspondant à votre Arduino UNO dans l'IDE Arduino.
- Commande associée : Outils > Port > [Votre port COM]
- Compilez et téléversez le code sur l'Arduino UNO.

Étape 3 : Configuration de l'Arduino Leonardo
- Téléchargez et ouvrez le fichier Graph_EG_A_JOUR.ino dans l'IDE Arduino.
- Installez préalablement la librairie TheThingsNetwork version 2.7.2.
- Commande associée : Croquis > Inclure une bibliothèque > Gérer les bibliothèques > Rechercher "TheThingsNetwork" et installer la version 2.7.2.
- Sélectionnez le bon port COM correspondant à votre Arduino Leonardo dans l'IDE Arduino.
- Commande associée : Outils > Port > [Votre port COM]
- Compilez et téléversez le code sur l'Arduino Leonardo.

Étape 4 : Installation de Node-RED et PostgreSQL sur Raspberry Pi
- Installez Node-RED sur votre Raspberry Pi 3. Suivez les instructions disponibles sur le site officiel de Node-RED.

  **sudo apt update**
  **sudo apt install -y nodered**

- Installez PostgreSQL :

  **sudo apt install -y postgresql postgresql-contrib**  
Créez une base de données et une table pour accueillir vos données.

  **CREATE DATABASE nom_de_votre_base;**  
  **\c nom_de_votre_base;**\
  **CREATE TABLE nom_de_votre_table (**
  **id SERIAL PRIMARY KEY,**
  **data JSONB,**
  **timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP**
**);**

Étape 5 : Configuration de Node-RED

- Importez le fichier Flow_Node_red.json dans Node-RED pour configurer le flux.
- Dans Node-RED, cliquez sur le menu en haut à droite > Import > collez le contenu du fichier ou sélectionnez-le directement.
- Modifiez le nœud MQTT avec les informations de connexion configurées sur TTN (par exemple, clé d'accès, URL du serveur).
- Modifiez les nœuds PostgreSQL dans Node-RED pour fournir les informations de connexion à votre base de données (nom d'utilisateur, mot de passe, nom de la base, etc.).
- 
Étape 6 : Déploiement

- Déployez le flux sur Node-RED en cliquant su le bouton "Déployer".





