# Bonobos Invaders | SAE 1.02
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

## Présentation
Notre jeu s'inspire du thème de la jungle et du jeu Space Invaders. Dans ce jeu, les vaisseaux sont des bonobos, les "Invaders" sont des baobabs, les missiles sont des bananes et les torpilles sont des branches. Il se joue en multijoueur et se découpe en plusieurs manches. Chaque joueur choisit son pseudo et peut ensuite jouer avec son partenaire. L'objectif est d'éliminer la vague de baobabs qui vous tire dessus. Un joueur a 3 vies. La manche suivante débute lorsque l'un des deux joueurs n'a plus de vie. Un joueur ayant éliminé l'ensemble des baobabs qui l'attaque gagne des feuilles bouclier résistant à 3 impact de banane. Le joueur peut également attaquer la vague de son adversaire.

## Notice du jeu

### Spécification :page_with_curl:
Le jeu se joue uniquement à 2 personnes.

Pour gagner, il faut avoir un score supérieur à son adversaire. Pour augmenter son score, il faut, soit attaquer les ennemis (plus ils sont loin plus le score obtenu est grand), soit attaquer l'adversaire. Si un des deux joueurs n'a plus de vie, la vague suivante se lance. Lorsqu'il n'y a plus de vague, l'écran de victoire/défaite se lance pour vous annoncer le vainqueur de ce match palpitant.

Ensuite au bout d'un certain temps, vous basculez sur l'écran des HighScores. Vous y apparaîtrez si vous avez fait un des 10 meilleurs scores.

Notez bien que si un ennemi atteint votre camp (la forêt), vous perdez une vie. Par ailleurs, plus le nombre d'ennemis franchissant cette zone augmente, plus vous perdez de vies.

> **Note**
> **N'oubliez pas d'installer _VLC_**. En effet, ce logiciel est utilisé pour la musique.

### Lancement du jeu :arrow_forward:
Pour lancer le jeu, assurez vous que tous les fichiers soient présents dans les sources et lancez le programme :
```
Bonobos_Invaders_V1.0.1/cmake-build-debug/S102
```

### Commandes :keyboard:

#### Commandes menu     

| Actions                      |          <center>Touches</center>         |
| ---------------------------  | :--------------------------------------------: |
| Se déplacer entre les bouton |          flèches de gauche et droite           |
| "Cliquer" sur un bouton      |                     entrée                     |
| Sortir du jeu                | Entrée une fois le bouton "retour" sélectionné |

#### Commandes multi

|         Actions       |  <center>Joueur Gauche</center> |    <center>Joueur Droit</center>   |
| :-------------------- |:---------------:|:-----------------:|
| Déplacer vers le haut |        z       |  flèche du haut   |
| Déplacer vers le bas  |        s       |  flèche du bas    |
| Tirer                 |        d       |  flèche de gauche |

#### Commandes différentes fenêtres

| Fenêtre       |      <center>Actions</center>      |    <center>Touches</center>     |
| :------------:| :---------------: |:-------------: |
| Menu et multi | - - - - - - - - - | Voir ci-dessus |
| HighScore     |  Sortir du menu   |         entrée |
| Crédits       |  Sortir du menu   |         entrée |


### Musique :musical_note:

La musique est jouée avec VLC, il faut donc faire attention, puisque si vous avez VLC d'ouvert pendant l'utilisation du jeu et que vous le quittez, celui-ci sera fermé.

> **Warning**
> Pour quitter le jeu, il est important d'utiliser le bouton à cet effet, qui est référencé plus haut. Sinon vous prenez le risque que la musique ne s'arrête plus jusqu'à l'arrêt forcé du processus !

**Un grand merci à ```@Grid``` pour avoir composé la musique du jeu !**

## Collaborateurs 🌟

**Graphic Designers**

- Egenscheviller Frédéric ```@frederic-egenscheviller```
- Métayer Sloane ```@sloaneMetayer```

**Level Designer**

- Ganassi Alexandre ```@AlexandreGanassi```

**Game Designers**

- Mariotti Alexis ```@Veuveuno```
- Pistoresi Marius ```@MariusPisto```
