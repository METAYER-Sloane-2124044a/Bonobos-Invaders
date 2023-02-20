/**
 *
 * @file    start_button.h
 * @author  METAYER SLOANE
 * @date    Janvier 2022
 * @version 1.0.1
 * @brief   Représente un bouton de début de jeu
 *
 **/

#ifndef S102_START_BUTTON_H
#define S102_START_BUTTON_H

#include "mingl/shape/shape.h"

namespace start_button {
    /**
     *
     * @param[in] window : Fenêtre graphique du jeu
     * @param[in] pos : Position (x,y) du coin extérieur gauche du bouton
     * @param[in] size : Taille du bouton
     * @fn draw(MinGL &window, nsGraphics::Vec2D &pos, unsigned size);
     */
    void draw(MinGL &window, nsGraphics::Vec2D &pos, unsigned size);
}
#endif // S102_START_BUTTON_H
