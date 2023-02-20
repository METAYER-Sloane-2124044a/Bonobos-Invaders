/**
 *
 * @file    highscore_button.h
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente le bouton de highscore
 *
 **/

#ifndef S102_HIGHSCORE_BUTTON_H
#define S102_HIGHSCORE_BUTTON_H


#include "mingl/shape/shape.h"

#include "mingl/transition/itransitionable.h"

namespace highscore_button {
    /**
     *
     * @param [in] window : Fenêtre graphique
     * @param [in] pos : Position de l'angle supérieur gauche du bouton
     * @param [in] size : Taille du bouton
     * @param [in] state : Etat du bouton sélectionné ou non (y/n)
     * @fn draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
     */
    void draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
}//namespace highscore_button
#endif // S102_HIGHSCORE_BUTTON_H
