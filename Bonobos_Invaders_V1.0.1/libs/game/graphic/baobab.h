/**
 *
 * @file    baobab.h
 * @author  METAYER SLOANE
 * @date    Décembre 2021
 * @version 1.0.1
 * @brief   Représente un baobab
 *
 **/

#ifndef S102_BAOBAB_H
#define S102_BAOBAB_H

#include "mingl/shape/shape.h"
#include "mingl/transition/itransitionable.h"

namespace baobab {
    /**
     *
     * @param[in] window : Fenêtre graphique
     * @param[in] pos : Emplacement (x,y) du centre de la base du baobab
     * @param[in] size : Taille du baobab
     * @fn  draw(MinGL& window, nsGraphics::Vec2D pos,unsigned size);
     */
    void draw(MinGL& window, nsGraphics::Vec2D pos,unsigned size);
}// namespace baobab
#endif // S102_BAOBAB_H
