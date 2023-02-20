/**
 * @file    startGame.h
 * @author  Marius PISTORESI
 * @date    Decembre 2021
 * @version 1.0
 * @brief   Permet de gérer le départ d'une partie
 **/

#include "mingl/mingl.h"
#include "mingl/shape/rectangle.h"
#include "game/graphic/start_button.h"

#ifndef S102_STARTGAME_H
#define S102_STARTGAME_H

namespace startGame{
    /**
     * @brief Structure du départ de la partie
     */
    struct StartGame{

        //Variables de la struct
        nsGraphics::Vec2D pos;
        std::vector<unsigned> size;

        /**
         * @brief Fonction constructeur de la struct StartGame
         * @param[in] window : fenêtre de jeu
         * @param[in] entSize : taille du start
         * @fn StartGame (MinGL &window, std::vector<unsigned> &entSize)
         */
        StartGame (MinGL &window, std::vector<unsigned> &entSize);

        /**
         * @brief Fonction qui affiche le départ de la partie
         * @param[in,out] window : fenêtre de jeu
         * @fn show(MinGL &window)
         */
        void show(MinGL &window);
    };
}
#endif //S102_STARTGAME_H
