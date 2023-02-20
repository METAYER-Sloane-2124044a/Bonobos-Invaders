/**
 *
 * @file    bonobo.h
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Décembre 2021
 * @version 1.0.1
 * @brief   Représente un bonobo
 *
 **/

#ifndef S102_BONOBO_H
#define S102_BONOBO_H

#include "mingl/shape/shape.h"
#include "mingl/transition/itransitionable.h"

namespace bonobo
{
    /**
     *
     * @param [in] window : Fenêtre graphique du jeu
     * @param [in] pos : Position du centre de la tête du bonobo
     * @param [in] radius : Rayon du cercle principal de la tête du bonobo
     * @fn draw(MinGL& window, nsGraphics::Vec2D &pos, unsigned radius);
     */
    void draw(MinGL& window, nsGraphics::Vec2D &pos, unsigned radius);
} // namespace bonobo

#endif // S102_BONOBO_H