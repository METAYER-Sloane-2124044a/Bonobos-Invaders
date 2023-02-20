/**
 *
 * @file    exit_button.cpp
 * @author  METAYER SLOANE
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente un bouton de sortie
 *
 **/

#include "game/graphic/exit_button.h"
#include "mingl/shape/triangle.h"
#include "mingl/shape/line.h"
#include "game/graphic/arc_circle.h"

using namespace std;

/**
 *
 * @param [in] window : Fenêtre graphique du jeu
 * @param [in] pos : Position du sommet de la flèche du bouton
 * @param [in] size : Taille de la flèche du bouton
 * @param [in] state : Etat sélectionné ou non (y/n)
 * @fn draw(MinGL &window, nsGraphics::Vec2D pos, unsigned size, char state);
 */
void exit_button::draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size, char state)
{
    unsigned x=pos.getX();
    unsigned y=pos.getY();
    unsigned height=size;
    unsigned width=size*2;

    //Bouton sélectionné
    if (state=='n') {
        //Triangle de la flèche
        window << nsShape::Triangle(nsGraphics::Vec2D(x, y),nsGraphics::Vec2D(x + width / 4, y - height / 3),
                                    nsGraphics::Vec2D(x + width / 4, y + height / 3), nsGraphics::KGreen,nsGraphics::KWhite);
        //Trait horizontal de la flèche
        window << nsShape::Line(nsGraphics::Vec2D(x + width / 4, y), nsGraphics::Vec2D(x + (2 * width / 4), y),
                                nsGraphics::KWhite,2);
        //Queue de la flèche
        window << nsShape::Arc_Circle(nsGraphics::Vec2D(x + (2 * width / 4), y - height / 5), height / 5,
                                      width / 5, 'r', nsGraphics::KWhite);
    }
    //Bouton non sélectionné
    else if (state=='y'){
        //Triangle de la flèche
        window << nsShape::Triangle(nsGraphics::Vec2D(x, y), nsGraphics::Vec2D(x + width / 4, y - height / 3),
                                    nsGraphics::Vec2D(x + width / 4, y + height / 3), nsGraphics::KGreen);
        //Trait horizontal de flèche
        window << nsShape::Line(nsGraphics::Vec2D(x + width / 4, y), nsGraphics::Vec2D(x + (2 * width / 4),y),
                                nsGraphics::KGreen,2);
        //Queue de la flèche
        window << nsShape::Arc_Circle(nsGraphics::Vec2D(x + (2 * width / 4), y - height / 5), height / 5,
                                      width / 5, 'r', nsGraphics::KGreen);
    }
} // draw()

