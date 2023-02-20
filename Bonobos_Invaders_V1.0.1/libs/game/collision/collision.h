/**
 * @file    collision.h
 * @author  Marius Pistoresi
 * @date    Décembre 2021
 * @version 1.0
 * @brief   Permet de gérer les collisions
 **/

#include <algorithm>

#include "game/entities/player.h"
#include "game/entities/torpedo.h"
#include "game/entities/startGame.h"
#include "game/entities/enemy.h"
#include "game/entities/shield.h"

#ifndef S102_COLLISION_H
#define S102_COLLISION_H

namespace collision{
    /**
     * @brief Génère les vecteurs de collisions
     * @param[
     * ] P : le vecteur de Player
     * @param[in,out] T : le vecteur de Torpedo
     * @fn void genColl(std::vector<torpedo::Torpedo> &T, std::vector<player::Player> &P)
     */
    void genColl(std::vector<torpedo::Torpedo> &T, std::vector<player::Player> &P);

    /**
     * @brief Prédicat de collision entre un point et une zone \n Cette fonction est équivalente à celle présente dans la bibliothèque MinGL cependant elle n'était pas adapter à notre cas.
     * @param[in] pos : position à vérifier
     * @param[in] firstCorner : premier coin de la zone à vérifier
     * @param[in] secondCorner : deuxième coin de la zone à vérifier
     * @return bool | Vrai si il y a collision faux sinon
     * @fn isColliding(nsGraphics::Vec2D &pos, nsGraphics::Vec2D &firstCorner, nsGraphics::Vec2D &secondCorner)
     */
    bool isColliding(nsGraphics::Vec2D &pos, nsGraphics::Vec2D &firstCorner, nsGraphics::Vec2D &secondCorner);

    /**
     * @brief Enlève les doublons dans un tableau trié
     * @param[in,out] vec : vecteur à trier
     * @fn supDouble(std::vector<unsigned> &vec)
     */
    void supDouble(std::vector<unsigned> &vec);

    /**
     * @brief Permet de gérer la collision des entitées
     * @param[in] players : vecteur des joueurs
     * @param[in,out] torpedos : vecteur des torpilles
     * @param[in] enemies : vecteur des enemies
     * @param[in] shields : vecteur des boulicers
     * @param[in] startGame : vecteur du lancement de jeu
     * @return std::vector<std::vector<char>> Valeurs possible dans les vecteurs : {val1, val2, val3, val4, val5} :\n
     * val1                    : {'t','p','s'}       //Torpedo, Player ou Start\n
     * val2                   : {'0','1'}            //Si val1 = 't' : d'ou vient la torpille si val1 = 'p' : position du joueur sinon rien\n
     * val3                    : {'e','p',char(unsigned)}//Si val1 = 't' : 'e' ou 'p' pour enemie ou joueur si val1 = 'p' : position de l'enemie sinon rien \n
     * val4                    : {char(unsigned)}   //Si val1 = 't' position de 'e' ou 'p' sinon rien\n
     * val5                     : {char(unsigned)}   //Si val1 = 't' direction de la torpilles sinon rien
     * @fn collision(std::vector<player::Player> &players, std::vector<torpedo::Torpedo> &torpedos, std::vector<enemy::Enemy> &enemies, std::vector<shield::Shield> &shields,std::vector<startGame::StartGame> &startGame)
     */
    std::vector<std::vector<char>> collision(std::vector<player::Player> &players, std::vector<torpedo::Torpedo> &torpedos, std::vector<enemy::Enemy> &enemies, std::vector<shield::Shield> &shields,std::vector<startGame::StartGame> &startGame);

}

#endif //S102_COLLISION_H
