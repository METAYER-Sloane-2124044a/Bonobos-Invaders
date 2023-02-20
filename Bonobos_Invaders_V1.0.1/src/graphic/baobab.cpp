/**
 *
 * @file    baobab.cpp
 * @author  METAYER SLOANE
 * @date    Décembre 2021
 * @version 1.0.1
 * @brief   Représente un baobab
 *
 **/

#include "game/graphic/baobab.h"
#include "mingl/shape/rectangle.h"
#include "game/graphic/half_circle.h"
#include "mingl/shape/circle.h"
#include "mingl/mingl.h"

using namespace std;

/**
 *
 * @param[in] window : Fenêtre graphique du jeu
 * @param[in] pos : Emplacement (x,y) du centre de la base du baobab
 * @param[in] size : Taille du baobab
 * @fn draw(MinGL& window, nsGraphics::Vec2D pos,unsigned size);
 */
void baobab::draw(MinGL& window, nsGraphics::Vec2D pos, unsigned size) {

    unsigned x1=pos.getX();
    unsigned y1=pos.getY();
    unsigned height=size;
    unsigned width=size/2;

    // Feuilles d'arrière plan
    window << nsShape::Circle(nsGraphics::Vec2D(x1-(width/12),y1-(6*height/11)),(y1-(3*height/8)-(y1-(6*height/11)))/2,nsGraphics::RGBAcolor(0, 86, 27));
    window << nsShape::Circle(nsGraphics::Vec2D(x1+(width/12),y1-(6*height/11)),(y1-(3*height/8)-(y1-(6*height/12)))/2,nsGraphics::RGBAcolor(0, 86, 27));
    //Tronc
    window << nsShape::Rectangle(nsGraphics::Vec2D(x1-(width/3),y1-(3*height/8)),nsGraphics::Vec2D(x1+(width/3),y1),nsGraphics::RGBAcolor(123, 83, 17));
    //Base de l'arbre
    window << nsShape::Rectangle(nsGraphics::Vec2D(x1-((width/2)*(window.getWindowSize().getX()/window.getWindowSize().getX())),(y1-(height/12))),nsGraphics::Vec2D(x1+((width/2)*(window.getWindowSize().getX()/window.getWindowSize().getX())),(y1+(height/12))),nsGraphics::RGBAcolor(170, 130, 64));

    //Feuille Gauche
    window << nsShape::Rectangle(nsGraphics::Vec2D((x1-(width/2)),y1-(6*height/12)),nsGraphics::Vec2D(x1-(width/12),y1-(4*height/11)),nsGraphics::RGBAcolor(9, 106, 9));
    //window << nsShape::Rectangle(nsGraphics::Vec2D(x1-(width/2),y1-(6*height/12)),nsGraphics::Vec2D(x1+(width/12),y1-(3*height/8)),nsGraphics::KGreen);
    window << nsShape::Circle(nsGraphics::Vec2D(x1-(width/2),y1-(4*height/11)-(y1-(4*height/11)-(y1-(6*height/12)))/2),(y1-(4*height/11)-(y1-(6*height/12)))/2,nsGraphics::RGBAcolor(9, 106, 9));
    window << nsShape::Circle(nsGraphics::Vec2D(x1-(width/12),y1-(4*height/11)-(y1-(4*height/11)-(y1-(6*height/12)))/2),(y1-(4*height/11)-(y1-(6*height/12)))/2,nsGraphics::RGBAcolor(9, 106, 9));
    window << half_circle::Half_Circle(nsGraphics::Vec2D(x1-(width/2)+(x1-(width/12)-(x1-(width/2)))/2,y1-(6*height/12)),(x1-(width/12)-(x1-(width/2)))/3,(y1-(3*height/8)-(y1-(6*height/12)))/2,'t',nsGraphics::RGBAcolor(9, 106, 9));

    //Feuille Droite
    window << nsShape::Rectangle(nsGraphics::Vec2D(x1,y1-(6*height/12)),nsGraphics::Vec2D(x1+(width/2),y1-(4*height/11)),nsGraphics::KGreen);
    window << nsShape::Circle(nsGraphics::Vec2D(x1,y1-(4*height/11)-(y1-(4*height/11)-(y1-(6*height/12)))/2),(y1-(4*height/11)-(y1-(6*height/12)))/2,nsGraphics::KGreen);
    window << nsShape::Circle(nsGraphics::Vec2D(x1+(width/2),y1-(4*height/11)-(y1-(4*height/11)-(y1-(6*height/12)))/2),(y1-(4*height/11)-(y1-(6*height/12)))/2,nsGraphics::KGreen);
    window << half_circle::Half_Circle(nsGraphics::Vec2D(x1+(x1+(width/2)-x1)/2,y1-(6*height/12)),(x1+(width/2)-x1)/3,(x1-(width/12)-(x1-(width/2)))/3,'t',nsGraphics::KGreen);
} // draw()


