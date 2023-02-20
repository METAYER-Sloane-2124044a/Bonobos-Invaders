/**
 * @file    enemy.h
 * @author  Marius Pistoresi
 * @date    Décembre 2021
 * @version 1.0
 * @brief   Permet de gérer les enemies
 **/

#include "mingl/mingl.h"

#include "mingl/shape/rectangle.h"

#include "game/yaml/configReader.h"

#include "game/entities/torpedo.h"

#include <random>
#include "game/graphic/baobab.h"

#ifndef S102_ENEMY_H
#define S102_ENEMY_H

namespace enemy{

    /**
     * @brief Initialisation de l'espace avec la config
     * @param[in] configMap : map des configuration
     * @fn init(std::map<std::string,std::string> &configMap)
     */
    void init(std::map<std::string,std::string> &configMap);

    /**
     * @brief Structure d'enemies
     */
    struct Enemy{

        //Variables des enemies
        nsGraphics::Vec2D pos;
        bool alive = true;
        std::vector<unsigned long> size;
	    bool goDown = true;
        char way;

        /**
         * @brief Fonction constructeur de la struct Enemy
         * @param[in] entPos : position du joueur
         * @param[in] entWay : direction du joueur
         * @fn Enemy(nsGraphics::Vec2D entPos, char entWay)
         */
        Enemy(nsGraphics::Vec2D entPos, char entWay);

        /**
         * @brief Fonction de mise à jour des enemies (déplacement et tir)
         * @param[in,out] enemies : vecteur des enemies
         * @param[in,out] torpedos : vecteur des torpilles
         * @param[in] window : fenêtre de jeu
         * @fn update(std::vector<Enemy> &enemies, std::vector<torpedo::Torpedo> &torpedos,MinGL &window)
         */
        void update(std::vector<Enemy> &enemies, std::vector<torpedo::Torpedo> &torpedos,MinGL &window);

        /**
         * @brief Rendu de l'enemie
         * @param[in,out] window : fenêtre de jeu
         * @fn show(MinGL &window)
         */
        void show(MinGL &window);

    };
}

#endif //S102_ENEMY_H
