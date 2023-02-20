/**
 *
 * @file    credit_button.h
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente le bouton de crédit
 *
 **/

#ifndef S102_CREDIT_BUTTON_H
#define S102_CREDIT_BUTTON_H


#include "mingl/shape/shape.h"
#include "mingl/transition/itransitionable.h"

namespace credit_button {
    /**
     *
     * @param[in] window : Fenêtre graphique du jeu
     * @param[in] pos : Position de l'angle supérieur gauche du bouton
     * @param[in] size : Taille du bouton
     * @param[in] state : Définit l'état, sélectionné (y/n)
     * @fn draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
     */
    void draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
} //namespace credit_button
#endif //S102_CREDIT_BUTTON_H