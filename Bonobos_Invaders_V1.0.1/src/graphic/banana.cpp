/**
 *
 * @file    banana.cpp
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Décembre 2021
 * @version 1.0.1
 * @brief   Représente une banane
 *
 **/

#include "game/graphic/banana.h"
#include "mingl/shape/rectangle.h"
#include "game/graphic/arc_circle.h"
#include "game/graphic/half_circle.h"
#include "mingl/shape/circle.h"
#include "mingl/mingl.h"

using namespace std;

/**
 *
 * @param [in] window : Fenêtre graphique
 * @param [in] pos : Emplacement (x,y) d'un point de la banane
 * @param [in] size : Taille de la banane
 * @param [in] direction : Sens de la banane (r/l)
 * @fn draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size, char direction);
 */
void banana::draw(MinGL& window, nsGraphics::Vec2D pos,unsigned size, char direction) {

    unsigned x = pos.getX();
    unsigned y = pos.getY();

    if (direction == 'l') {
        //Banane tirée par le joueur de gauche
        //Queue de la banane
        window << nsShape::Circle(nsGraphics::Vec2D(x - size * 0.90, y - size / 10), (size / 10),
                                  nsGraphics::RGBAcolor{218, 235, 49});
        window << nsShape::Circle(nsGraphics::Vec2D(x - size * 0.90, y - size / 15), (size / 10),
                                  nsGraphics::RGBAcolor{218, 235, 49});
        window << nsShape::Circle(nsGraphics::Vec2D(x - size * 0.90, y - size / 8), (size / 10),
                                  nsGraphics::RGBAcolor{218, 235, 49});
        //Corps de la banane
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x, y), (size), (size / 1.67), 'b', nsGraphics::KYellow);
        window << nsShape::Arc_Circle(nsGraphics::Vec2D(x, y - size / 8), (size), (size / 1.67), 'b',
                                      nsGraphics::KBlack);
        //Bout de la banane
        window << nsShape::Circle(nsGraphics::Vec2D(x + size * 0.98, y), (size / 14),
                                  nsGraphics::RGBAcolor{141, 75, 61});
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x, y - size / 3), (size), (size / 1.67), 'b',
                                       nsGraphics::KBlack);
    } else if (direction == 'r') {
        //Banane tirée par le joueur de droite
        //Queue de la banane
        window << nsShape::Circle(nsGraphics::Vec2D(x + size * 0.90, y - size / 10), (size / 10),
                                  nsGraphics::RGBAcolor{218, 235, 49});
        window << nsShape::Circle(nsGraphics::Vec2D(x + size * 0.90, y - size / 15), (size / 10),
                                  nsGraphics::RGBAcolor{218, 235, 49});
        window << nsShape::Circle(nsGraphics::Vec2D(x + size * 0.90, y - size / 8), (size / 10),
                                  nsGraphics::RGBAcolor{218, 235, 49});
        //Corps de la banane
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x, y), (size), (size / 1.67), 'b', nsGraphics::KYellow);
        window << nsShape::Arc_Circle(nsGraphics::Vec2D(x, y - size / 8), (size), (size / 1.67), 'b',
                                         nsGraphics::KBlack);
        //Bout de la banane
        window << nsShape::Circle(nsGraphics::Vec2D(x - size * 0.98, y), (size / 14),
                                  nsGraphics::RGBAcolor{141, 75, 61});
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x, y - size / 3), (size), (size / 1.67), 'b',
                                       nsGraphics::KBlack);
    }
} //draw()


