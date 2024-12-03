# Path Tracer

## Description

**Path Tracer** est un projet conçu pour simuler de manière réaliste l'interaction de la lumière avec les surfaces à l'
aide de la technique de lancer de rayons (path tracing). Ce projet met un point d'honneur à respecter les **principes
SOLID**, garantissant ainsi un code maintenable, extensible et modulaire.

Le path tracer est structuré pour permettre une compréhension claire de chaque composant, tout en restant flexible pour
des améliorations ou des extensions futures.

## Fonctionnalités principales

- Simulation réaliste d'éclairage global à l'aide de path tracing.
- Gestion optimisée des rayons et des interactions avec les surfaces.
- Système modulaire permettant l'ajout facile de nouvelles primitives géométriques ou de shaders.
- Algorithmes respectant les principes SOLID :
    - **S** : Chaque classe a une responsabilité unique.
    - **O** : Le projet est ouvert à l'extension tout en restant fermé à la modification.
    - **L** : Les sous-classes peuvent remplacer leurs classes parentes sans casser la fonctionnalité.
    - **I** : Les interfaces sont spécifiques aux besoins des clients.
    - **D** : Les dépendances sont gérées par injection, limitant le couplage.

## Prérequis

- **Langage** : C++ (standard C++17 ou supérieur recommandé)
- **Compilateur** : GCC, Clang ou MSVC compatible C++17+
- **Dépendances** :
    - Bibliothèque standard C++

## Compilation et execution

```bash
mkdir build && cd build
cmake ..
make
./path_tracer
```

## Utilisation

- Configurez la scène en modifiant le fichier `main.cpp`.
- Lancez le programme pour générer des rendus réalistes.

## Auteurs

- **Mathéo DUCROT** : DUCM25120100
- **Maxime JINGEAUX** : JINM24110300
