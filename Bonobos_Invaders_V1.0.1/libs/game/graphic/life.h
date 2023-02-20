/**
 *
 * @file    life.h
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Décembre 2021
 * @version 1.0.1
 * @brief   Représente une coeur
 *
 **/

#ifndef S102_LIFE_H
#define S102_LIFE_H

#include "mingl/shape/shape.h"

namespace life
{
    /**
     *
     * @param [in] window : Fenêtre graphique du jeu
     * @param [in] pos : Position du cercle haut-gauche du coeur
     * @param [in] size : Rayon des cercles du coeur
     * @fn draw(MinGL& window, nsGraphics::Vec2D pos, unsigned &size);
     */
    void draw(MinGL& window, nsGraphics::Vec2D pos, unsigned &size);
} // namespace life

#endif //S102_LIFE_H
