/**
 *
 * @file    play_button.h
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente un bouton de jeu
 *
 **/
#ifndef S102_PLAY_BUTTON_H
#define S102_PLAY_BUTTON_H

#include "mingl/shape/shape.h"
#include "mingl/transition/itransitionable.h"

namespace play_button {
    /**
     *
     * @param[in] window : Fenêtre graphique du jeu :
     * @param [in] pos : Position de l'angle supérieur gauche du rectangle
     * @param [in] size : Taille du rectangle du bouton
     * @param [in] state : Etat sélectionné ou non du bouton (y/n)
     * @fn draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
     */
    void draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
}
#endif // S102_PLAY_BUTTON_H
