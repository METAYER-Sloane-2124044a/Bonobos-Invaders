/**
 *
 * @file    start_button.cpp
 * @author  METAYER SLOANE
 * @date    Janvier 2022
 * @version 1.0.1
 * @brief   Représente un bouton de début de jeu
 *
 **/

#include "game/graphic/start_button.h"
#include "mingl/shape/rectangle.h"
#include "mingl/gui/text.h"

using namespace std;

/**
 *
 * @param[in] window : Fenêtre graphique du jeu
 * @param[in] pos : Position (x,y) du coin extérieur gauche du bouton
 * @param[in] size : Taille du bouton
 * @fn draw(MinGL &window, nsGraphics::Vec2D &pos, unsigned size);
 */
void start_button::draw(MinGL& window, nsGraphics::Vec2D &pos, unsigned size)
{
    unsigned x=pos.getX();
    unsigned y=pos.getY();

    //Contour du bouton
    window << nsShape::Rectangle(nsGraphics::Vec2D(x-size/1.9,y-size/3.8), nsGraphics::Vec2D(x+size/1.9, y+size/3.8), nsGraphics::KWhite);
    //Fond et texte du bouton
    window << nsShape::Rectangle(nsGraphics::Vec2D(x-size/2,y-size/4), nsGraphics::Vec2D(x+size/2, y+size/4), nsGraphics::KBlack);
    window << nsGui::Text(nsGraphics::Vec2D(x-30, y+6), "START", nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
} // draw()

