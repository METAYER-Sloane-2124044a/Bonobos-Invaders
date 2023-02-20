/**
 * @file    torpedos.h
 * @author  Marius PISTORESI
 * @date    Decembre 2021
 * @version 1.0
 * @brief   Permet de gérer les torpilles
 **/

#include "mingl/mingl.h"
#include "mingl/shape/rectangle.h"

#include "game/yaml/configReader.h"
#include "game/graphic/branch.h"
#include "game/graphic/banana.h"

#ifndef S102_TORPEDO_H
#define S102_TORPEDO_H

namespace torpedo {

    /**
     * @brief Permet de gérer la configuration dans l'espace vide
     * @param[in] configMap : map de la configuration du jeu
     * @fn init(std::map<std::string,std::string> &configMap)
     */
    void init(std::map<std::string,std::string> &configMap);

    /**
     * @brief Structure pour les torpilles
     */
    struct Torpedo {

        //Variable des torpilles
        unsigned from;
        unsigned to;
        nsGraphics::Vec2D pos;
        std::vector<unsigned long> size;
        unsigned speedLimit;
        unsigned speedCount;

        /**
         * @brief Fonction constructeur de la structure Torpedo
         * @param[in] entFrom : Ientité du tireur (0 pour invaders, 1 pour player 1, 2 pour player 2)
         * @param[in] entTo : Sens dans lequel part la torpille (0 gauche, 1 droite)
         * @param[in] entPosX : position X de départ de la torpille
         * @param[in] entPosY : Position Y de départ de la torpille
         * @fn Torpedo(unsigned entFrom, unsigned entTo, int entPosX, int entPosY)
         */
        Torpedo(unsigned entFrom, unsigned entTo, int entPosX, int entPosY);

        /**
         * @brief Fonction de mise a jour des positions de la torpile
         * @fn void update()
         */
        void update();

        /**
         * @brief Affiche la torpille
         * @param[in,out] window : fenêtre de jeu
         * @fn show(MinGL &window)
         */
        void show(MinGL &window);
    };
}
#endif //S102_TORPEDO_H