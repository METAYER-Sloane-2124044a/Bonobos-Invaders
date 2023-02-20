/**
 *
 * @file    shieldG.h
 * @author  METAYER SLOANE
 * @date    Janvier 2022
 * @version 1.0.1
 * @brief   Représente un bouclier en forme de feuille
 *
 **/

#ifndef S102_SHIELDG_H
#define S102_SHIELDG_H

#include "mingl/shape/shape.h"

namespace shield {
    /**
     *
     * @param[in] window : Fenêtre graphique du jeu
     * @param[in] pos : Position du centre de la feuille
     * @param[in] radius : Rayon de la feuille
     * @param[in] size : Largueur du bouclier divisé par 2 (Taille des demi-cercle du bouclier)
     * @param[in] state : Etat du bouclier (1, 2, 3)
     * @fn draw(MinGL &window, nsGraphics::Vec2D &pos, unsigned radius, unsigned size, unsigned state);
     */
    void draw(MinGL &window, nsGraphics::Vec2D &pos, unsigned radius, unsigned size, unsigned state);
}
#endif // S102_SHIELDG_H
