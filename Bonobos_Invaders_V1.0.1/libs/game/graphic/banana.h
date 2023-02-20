/**
 *
 * @file    banana.h
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Décembre 2021
 * @version 1.0.1
 * @brief   Représente une banane
 *
 **/

#ifndef S102_BANANA_H
#define S102_BANANA_H

#include "mingl/shape/shape.h"
#include "mingl/transition/itransitionable.h"


namespace banana {
    /**
     *
     * @param [in] window : Fenêtre graphique
     * @param [in] pos : Emplacement (x,y) d'un point de la banane
     * @param [in] size : Taille de la banane
     * @param [in] direction : Sens de la banane (r/l)
     * @fn draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size, char direction);
     */
    void draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size, char direction);
} // namespace banana

#endif // S102_BANANA_H
