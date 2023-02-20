/**
 *
 * @file    branch.h
 * @author  METAYER SLOANE
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente une branche
 *
 **/

#ifndef S102_BRANCH_H
#define S102_BRANCH_H

#include "mingl/mingl.h"

namespace branch
{
    /**
     *
     * @param[in] window : Fenêtre graphique du jeu
     * @param[in] pos : Position du coin extérieur gauche de la branche
     * @param[in] size : Taille de la branche
     * @fn draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size);
     */
    void draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size);
} // namespace branch

#endif // S102_BRANCH_H

