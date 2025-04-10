# Projet Tetris en C

Ce projet consiste à concevoir et implémenter le jeu classique Tetris en langage C, en suivant une approche modulaire et structurée. Le projet est réalisé dans le cadre du module Développement d'Applications et en lien avec la thématique Valorisation de la donnée et cybersécurité.

## Table des Matières

1. [Introduction](#introduction)
2. [Objectifs](#objectifs)
3. [Fonctionnalités Principales](#fonctionnalités-principales)
4. [Structure du Projet](#structure-du-projet)
5. [Installation et Configuration](#installation-et-configuration)
6. [Utilisation](#utilisation)
7. [Contribution](#contribution)
8. [Licence](#licence)
9. [Auteurs](#auteurs)
10. [Remerciements](#remerciements)

## Introduction

Le Tetris est un jeu vidéo emblématique où les joueurs doivent empiler et organiser des pièces de formes différentes pour former des lignes complètes. Ce projet vise à recréer ce jeu en utilisant le langage C, avec une interface utilisateur en mode texte basée sur la bibliothèque ncurses.

## Objectifs

- **Conception de l'architecture** : Définir une architecture modulaire permettant la réutilisation et la maintenance du code.
- **Modélisation** : Représenter les éléments du jeu sous forme de structures de données adaptées.
- **Développement** : Implémenter les fonctionnalités du jeu en respectant les bonnes pratiques de programmation en C.
- **Tests et Validation** : Concevoir des tests unitaires et d'intégration pour valider le fonctionnement global du jeu.
- **Améliorations** : Proposer des pistes d'amélioration comme l'ajout de niveaux de difficulté, gestion des scores, et améliorations graphiques.

## Fonctionnalités Principales

- **Gestion des pièces (Tetriminos)** : 7 formes différentes, chacune pouvant être orientée dans quatre directions.
- **Grille de jeu** : Zone de jeu de 10 colonnes x 20 lignes où les pièces tombent et peuvent être déplacées ou tournées.
- **Détection de collisions** : Gestion des mouvements et des collisions des pièces.
- **Suppression de lignes** : Lorsqu'une ligne est complétée, elle est supprimée, et les lignes supérieures descendent.
- **Interface utilisateur** : Utilisation de la bibliothèque ncurses pour une interface pseudo-graphique en mode terminal.

## Structure du Projet

Le projet est organisé en plusieurs modules, chacun ayant ses propres fichiers headers (.h) et fichiers sources (.c).

- **Fichiers headers (.h)** : Déclarations des structures et des fonctions.
- **Fichiers sources (.c)** : Implémentation des fonctions et de la logique du jeu.
- **Bibliothèque ncurses** : Utilisée pour l'interface utilisateur en mode texte.

### Arborescence des Fichiers

```
CTris/
│
├── src/
│   ├── main.c
│   ├── tetris.h
│   ├── tetris.c
│   ├── tetrimino.h
│   ├── tetrimino.c
│   ├── defines.h
│   └── ...
│
├── CMakeLists.txt
├── README.md
└── ...
```

## Installation et Configuration

### Prérequis

- Compilateur C (GCC recommandé)
- CMake
- Bibliothèque ncurses

### Installation

1. **Installer ncurses** :
   ```bash
   sudo apt install -y ncurses
   ```

2. **Cloner le dépôt** :
   ```bash
   git clone https://github.com/SashaMRT/CTris.git
   cd CTris
   ```

3. **Compiler le projet** :
   Utilisez CMake pour compiler le projet à partir des fichiers sources fournis.
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Utilisation

Pour lancer le jeu, exécutez le binaire généré dans le dossier `build` :
```bash
./CTris
```

Utilisez les touches fléchées pour déplacer et tourner les pièces. Appuyez sur 'q' pour quitter le jeu.

## Contribution

Les contributions sont les bienvenues ! Pour contribuer, veuillez suivre ces étapes :

1. Forkez le dépôt.
2. Créez une branche pour votre fonctionnalité (`git checkout -b feature/AmazingFeature`).
3. Committez vos modifications (`git commit -m 'Add some AmazingFeature'`).
4. Pushez vers la branche (`git push origin feature/AmazingFeature`).
5. Ouvrez une Pull Request.

## Licence

Ce projet est sous licence [GNU General Public License v3.0].<br/>
Voir le fichier [LICENSE](LICENSE) pour plus de détails.

## Auteurs

- **Sasha Marie te Rehorst** - [Lien vers profil](https://github.com/SashaMRT)
- **Ylan Albicini** - [Lien vers profil](https://github.com/ylalb)
- **Gael Guinaliu** - [Lien vers profil](https://github.com/GoneSalam)

## Remerciements

- Merci à tous les contributeurs qui ont aidé à améliorer ce projet.
- Merci à la communauté open-source pour les outils et les ressources utilisés dans ce projet.