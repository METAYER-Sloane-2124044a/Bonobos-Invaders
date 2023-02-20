/**
 *
 * @file    life.cpp
 * @author  EGENSCHEVILLER FREDERIC
 * @date    Janvier 2022
 * @version 1.0.1
 * @brief   Représente une vie d'un joueur
 *
 **/

#include "game/graphic/life.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/triangle.h"
#include "mingl/mingl.h"

using namespace std;

/**
 *
 * @param [in] window : Fenêtre graphique du jeu
 * @param [in] pos : Position du cercle haut-gauche du coeur
 * @param [in] size : Rayon des cercles du coeur
 * @fn draw(MinGL& window, nsGraphics::Vec2D pos, unsigned &size);
 */
void life::draw(MinGL& window, nsGraphics::Vec2D pos, unsigned &size)
{
    unsigned x=pos.getX();
    unsigned y=pos.getY();

    //Haut du coeur
    window << nsShape::Circle(nsGraphics::Vec2D(x, y), size, nsGraphics::KRed);
    window << nsShape::Circle(nsGraphics::Vec2D(x+size*1.8, y), size, nsGraphics::KRed);
    //Bas du coeur
    window << nsShape::Triangle(nsGraphics::Vec2D(x-size*2, y+size/3), nsGraphics::Vec2D(x+size*3.2, y+size/3), nsGraphics::Vec2D(x+size, y+size*2.8), nsGraphics::KBlack);
    window << nsShape::Triangle(nsGraphics::Vec2D(x-size*0.95, y+size/3), nsGraphics::Vec2D(x+size*2.75, y+size/3), nsGraphics::Vec2D(x+size, y+size*2.8), nsGraphics::KRed);
}//draw()