/**
 * @file    shield.h
 * @author  Marius PISTORESI
 * @date    Janvier 2022
 * @version 1.0
 * @brief   Permet de gérer les boucliers
 **/

#include "mingl/mingl.h"
#include "mingl/shape/rectangle.h"
#include "game/graphic/shieldG.h"

#ifndef S102_SHIELD_H
#define S102_SHIELD_H

namespace shield{

    /**
     * @brief Structure des bouclier
     */
    struct Shield{
        //Variable de la structure
        unsigned life;
        nsGraphics::Vec2D pos;

        /**
         * @brief Fonction constructeur du bouclier
         * @param[in] entPos : position du bouclier
         * @fn Shield(const nsGraphics::Vec2D &entPos)
         */
        Shield(const nsGraphics::Vec2D &entPos);

        /**
         * @brief Permet d'afficher graphiquement le bouclier
         * @param[in,out] window : fenêtre de jeu
         * @fn show(MinGL &window)
         */
        void show(MinGL &window);
    };

    /**
     * @brief Permet de générer tous les boucliers par rapport à la fenêtre de jeu
     * @param[in,out] shields : vecteur de bouclier
     * @param[in] window : fenêtre de jeu
     * @fn genShield(std::vector<Shield> &shields, MinGL &window)
     */
    void genShield(std::vector<Shield> &shields, MinGL &window);
}

#endif //S102_SHIELD_H
