/**
 *
 * @file    exit_button.h
 * @author  METAYER SLOANE
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente un bouton de sortie
 *
 **/
#ifndef S102_EXIT_BUTTON_H
#define S102_EXIT_BUTTON_H


#include "mingl/shape/shape.h"

#include "mingl/transition/itransitionable.h"
namespace exit_button {
    /**
     *
     * @param [in] window : Fenêtre graphique du jeu
     * @param [in] pos : Position du sommet de la flèche du bouton
     * @param [in] size : Taille de la flèche du bouton
     * @param [in] state : Etat sélectionné ou non (y/n)
     * @fn draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
     */
    void draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
}//namespace exit_button
#endif //S102_EXIT_BUTTON_H