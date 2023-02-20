/**
 *
 * @file    highscore_button.cpp
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Décembre 2021
 * @version 1.0.1
 * @brief   Représente un bouton de high score
 *
 **/

#include "game/graphic/highscore_button.h"
#include "mingl/shape/rectangle.h"
#include "mingl/gui/text.h"
#include "mingl/mingl.h"

using namespace std;

/**
 *
 * @param [in] window : Fenêtre graphique
 * @param [in] pos : Position de l'angle supérieur gauche du bouton
 * @param [in] size : Taille du bouton
 * @param [in] state : Etat du bouton sélectionné ou non (y/n)
 * @fn draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
 */
void highscore_button::draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size, char state)
{
    unsigned x=pos.getX();
    unsigned y=pos.getY();

    //Contour du bouton, si sélectionné
    if(state=='n')
        window << nsShape::Rectangle(nsGraphics::Vec2D(x-size/1.9,y-size/3.8), nsGraphics::Vec2D(x+size/1.9, y+size/3.8), nsGraphics::KWhite);
    //Bouton de high score
    window << nsShape::Rectangle(nsGraphics::Vec2D(x-size/2,y-size/4), nsGraphics::Vec2D(x+size/2, y+size/4), nsGraphics::KGreen);
    window << nsGui::Text(nsGraphics::Vec2D(x-40, y+6), "HighScore", nsGraphics::KWhite, nsGui::GlutFont::BITMAP_9_BY_15);
}//draw()
