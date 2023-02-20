/**
 *
 * @file    branch.cpp
 * @author  METAYER SLOANE
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente une branche
 *
 **/

#include "game/graphic/branch.h"
#include "mingl/shape/rectangle.h"
#include "mingl/shape/line.h"

using namespace std;

/**
 *
 * @param[in] window : Fenêtre graphique du jeu
 * @param[in] pos : Position du coin extérieur gauche de la branche
 * @param[in] size : Taille de la branche
 * @fn draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size);
 */
void branch::draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size)
{
    unsigned x1=pos.getX();
    unsigned y1=pos.getY();
    unsigned x2=pos.getX()+ size;
    unsigned y2=pos.getY()+ size/2;

    //Corps de la branche
    window << nsShape::Rectangle(nsGraphics::Vec2D(x1,y1), nsGraphics::Vec2D(x2,y2),nsGraphics::RGBAcolor(123, 83, 17));
    //Rayures de la branche
    unsigned cpt=0;
    for(unsigned i=1; x1+i*((x2-x1)/6) <= x1+5*((x2-x1)/6);++i){
        if (cpt==0) {
            //Rayures verticales haut
            window << nsShape::Line(nsGraphics::Vec2D((x1 + i * ((x2 - x1) / 6)), y1 + (y2 - y1) / 6),
                                    nsGraphics::Vec2D(x1 + i * ((x2 - x1) / 6), y1 + (y2 - y1) / 2),
                                    nsGraphics::RGBAcolor{84,31,1},
                                    2.5);
            //Mini branches sortantes bas
            window << nsShape::Line(nsGraphics::Vec2D((x1 + i * ((x2 - x1) / 6)),y2),
                                    nsGraphics::Vec2D(x1 + (i+1) * ((x2 - x1) / 6),y2+ (y2 - y1) / 6),
                                    nsGraphics::RGBAcolor{84,31,1},
                                    2.5);
            cpt =1;
        }
        else{
            //Rayures verticales bas
            window << nsShape::Line(nsGraphics::Vec2D((x1 + i * ((x2 - x1) / 6)), y1 + (y2 - y1) / 2),
                                    nsGraphics::Vec2D(x1 + i * ((x2 - x1) / 6), y1 + 5*(y2 - y1) / 6),
                                    nsGraphics::RGBAcolor{84,31,1},
                                    2.5);
            //Mini branches sortantes haut
            window << nsShape::Line(nsGraphics::Vec2D((x1 + i * ((x2 - x1) / 6)),y1),
                                    nsGraphics::Vec2D(x1 + (i+1) * ((x2 - x1) / 6),y1- ((y2 - y1) / 6)),
                                    nsGraphics::RGBAcolor{84,31,1},
                                    2.5);
            cpt=0;
        }
    }
} // draw()