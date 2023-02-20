/**
 *
 * @file    bonobo.cpp
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Décembre 2021
 * @version 1.0.1
 * @brief   Représente un bonobo
 *
 **/

#include "game/graphic/bonobo.h"
#include "game/graphic/arc_circle.h"
#include "../../libs/mingl/shape/circle.h"
using namespace std;

/**
 *
 * @param [in] window : Fenêtre graphique du jeu
 * @param [in] pos : Position du centre de la tête du bonobo
 * @param [in] radius : Rayon du cercle principal de la tête du bonobo
 * @fn draw(MinGL& window, nsGraphics::Vec2D &pos, unsigned radius);
 */
void bonobo::draw(MinGL& window, nsGraphics::Vec2D &pos, unsigned radius)
{
    unsigned x=pos.getX();
    unsigned y=pos.getY();

    //Oreilles
    window << nsShape::Circle(nsGraphics::Vec2D(x-3*radius/4, y-(radius/2)), (radius/2.7), nsGraphics::RGBAcolor{141, 75, 61});
    window << nsShape::Circle(nsGraphics::Vec2D(x+3*radius/4, y-(radius/2)), (radius/2.7), nsGraphics::RGBAcolor{141, 75, 61});
    //Tête
    window << nsShape::Circle(nsGraphics::Vec2D(x, y), radius, nsGraphics::RGBAcolor{121,21,0});
    //Fond 2 des 2 yeux
    window << nsShape::Circle(nsGraphics::Vec2D(x-radius/4, y-radius/3), (radius/3.3), nsGraphics::RGBAcolor{207,153,141});
    window << nsShape::Circle(nsGraphics::Vec2D(x+radius/4, y-radius/3), (radius/3.3), nsGraphics::RGBAcolor{207,153,141});
    //Fond 1 des 2 yeux
    window << nsShape::Circle(nsGraphics::Vec2D(x-radius/4, y-radius/3), (radius/5.25), nsGraphics::KBlack);
    window << nsShape::Circle(nsGraphics::Vec2D(x+radius/4, y-radius/3), (radius/5.25), nsGraphics::KBlack);
    //2 yeux
    window << nsShape::Circle(nsGraphics::Vec2D(x-radius/4, y-radius/3), (radius/25), nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+radius/4, y-radius/3), (radius/25), nsGraphics::KWhite);
    //Museau
    window << nsShape::Circle(nsGraphics::Vec2D(x, y+radius/2), (radius/1.6), nsGraphics::RGBAcolor{164, 121, 100});
    //Sourire et narines
    window << nsShape::Arc_Circle(nsGraphics::Vec2D(x, y+radius/2), (radius/5), (radius/5),'b',nsGraphics::KBlack);
    window << nsShape::Circle(nsGraphics::Vec2D(x-radius/7, y+radius/4), (radius/25), nsGraphics::KBlack);
    window << nsShape::Circle(nsGraphics::Vec2D(x+radius/7, y+radius/4), (radius/25), nsGraphics::KBlack);
} // draw()