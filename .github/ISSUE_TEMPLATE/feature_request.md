# Demandes de Fonctionnalités pour le Projet CTris

Ce document décrit les demandes de fonctionnalités pour le projet CTris, un jeu Tetris implémenté en C. Chaque demande de fonctionnalité doit être détaillée avec une description, une justification et toutes informations ou considérations supplémentaires.

## Table des Matières

1. [Modèle de Demande de Fonctionnalité](#modèle-de-demande-de-fonctionnalité)
2. [Fonctionnalités Proposées](#fonctionnalités-proposées)
3. [Soumission d'une Demande de Fonctionnalité](#soumission-dune-demande-de-fonctionnalité)

## Modèle de Demande de Fonctionnalité

Lorsque vous soumettez une demande de fonctionnalité, veuillez utiliser le modèle suivant :

```markdown
### Titre de la Fonctionnalité

**Description :**
[Fournissez une description détaillée de la fonctionnalité. Que fait-elle ? Comment fonctionne-t-elle ?]

**Justification :**
[Expliquez pourquoi cette fonctionnalité est nécessaire. Quel problème résout-elle ? Comment améliore-t-elle le projet ?]

**Notes Supplémentaires :**
[Incluez toutes informations, considérations ou dépendances supplémentaires liées à cette fonctionnalité.]
```

## Fonctionnalités Proposées

### Mode Graphique Amélioré

**Description :**
Implémentez un mode graphique amélioré utilisant une bibliothèque graphique (par exemple, SDL) pour offrir une expérience visuellement plus attrayante par rapport au mode texte actuel basé sur ncurses.

**Justification :**
Un mode graphique amélioré rendrait le jeu plus attrayant et engageant pour les utilisateurs, augmentant potentiellement sa popularité et son utilisation.

**Notes Supplémentaires :**
- Cette fonctionnalité nécessiterait des dépendances supplémentaires et potentiellement des instructions de configuration plus complexes.
- Envisagez de fournir une option de basculement entre les modes texte et graphique.

### Mode Multijoueur

**Description :**
Ajoutez un mode multijoueur où deux joueurs peuvent s'affronter sur le même appareil ou via un réseau.

**Justification :**
La fonctionnalité multijoueur peut considérablement augmenter l'engagement et le plaisir des utilisateurs en permettant un gameplay compétitif.

**Notes Supplémentaires :**
- Les capacités réseau devraient être implémentées pour le multijoueur en ligne.
- Envisagez les options multijoueur à écran partagé et en réseau.

### Thèmes Personnalisables

**Description :**
Permettez aux utilisateurs de personnaliser l'apparence du jeu avec différents thèmes, y compris les schémas de couleurs et les designs de blocs.

**Justification :**
Les options de personnalisation peuvent améliorer la satisfaction des utilisateurs en leur permettant de personnaliser leur expérience de jeu.

**Notes Supplémentaires :**
- Les thèmes pourraient être partagés ou téléchargés depuis un dépôt communautaire.
- Assurez-vous que les thèmes personnalisés n'affectent pas les mécanismes de jeu.

### Suivi des Scores Élevés

**Description :**
Implémentez un système de suivi des scores élevés qui enregistre et affiche les scores les plus élevés réalisés par les joueurs.

**Justification :**
Le suivi des scores élevés ajoute un élément compétitif et fournit aux joueurs des objectifs à atteindre.

**Notes Supplémentaires :**
- Envisagez d'intégrer un classement en ligne pour une compétition mondiale.
- Assurez-vous que les données de score sont stockées de manière sécurisée et peuvent être réinitialisées si nécessaire.

## Soumission d'une Demande de Fonctionnalité

1. **Forkez le Dépôt**: Créez un fork du dépôt.
2. **Créez une Nouvelle Branche**: Créez une nouvelle branche pour votre demande de fonctionnalité (par exemple, `feature/nom-de-la-fonctionnalité`).
3. **Ajoutez votre Demande de Fonctionnalité**: Ajoutez votre demande de fonctionnalité à ce document en utilisant le modèle fourni.
4. **Commit et Push**: Commitez vos changements et pushez la branche vers votre fork.
5. **Ouvrez une Pull Request**: Ouvrez une pull request avec un titre clair et une description de votre demande de fonctionnalité.

Nous accueillons toutes les demandes de fonctionnalités et apprécions vos contributions pour améliorer le projet CTris !