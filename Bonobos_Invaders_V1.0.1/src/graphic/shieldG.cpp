/**
 *
 * @file    shieldG.cpp
 * @author  METAYER SLOANE
 * @date    Janvier 2022
 * @version 1.0.1
 * @brief   Représente un bouclier en forme de feuille
 *
 **/

#include "game/graphic/shieldG.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/line.h"
#include "game/graphic/half_circle.h"
#include "mingl/mingl.h"

using namespace std;

/**
 *
 * @param[in] window : Fenêtre graphique du jeu
 * @param[in] pos : Position du centre de la feuille
 * @param[in] radius : Rayon de la feuille
 * @param[in] size : Largueur du bouclier divisé par 2 (Taille des demi-cercle du bouclier)
 * @param[in] state : Etat du bouclier (1, 2, 3)
 * @fn draw(MinGL &window, nsGraphics::Vec2D &pos, unsigned radius, unsigned size, unsigned state);
 */
void shield::draw(MinGL& window, nsGraphics::Vec2D &pos, unsigned radius, unsigned size, unsigned state)
{
    unsigned x= pos.getX();
    unsigned y=pos.getY();

    //Bouclier neuf
    if (state==3){
        //Corps de la feuille
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x,y),radius,size,'l',nsGraphics::KGreen);
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x,y),radius,size,'r',nsGraphics::KGreen);

        //Rayures de la feuille
        window << nsShape::Line(nsGraphics::Vec2D(x,y-radius+radius/4),nsGraphics::Vec2D(x,y+3*radius/4),nsGraphics::KMaroon,2.f);
        for (unsigned y2=y-radius+2*radius/4; y2<y+3*radius/4 ;--y2){
            window << nsShape::Line (nsGraphics::Vec2D(x,y2),nsGraphics::Vec2D(x-size/2,y2-size/2),nsGraphics::RGBAcolor{76,34,12},1.f);
            window << nsShape::Line (nsGraphics::Vec2D(x,y2),nsGraphics::Vec2D(x+size/2,y2-size/2),nsGraphics::RGBAcolor{76,34,12},1.f);
            y2+=radius/4;
        }
        //Queue de la feuille
        window << nsShape::Line (nsGraphics::Vec2D(x,y+radius),nsGraphics::Vec2D(x,y+radius+size/2),nsGraphics::KGreen,2.f);
    }
    //Bouclier abîmé
    else if(state==2){
        //Corps de la feuille
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x,y),radius,size,'l',nsGraphics::RGBAcolor{228,221,73 });
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x,y),radius,size,'r',nsGraphics::RGBAcolor{228,221,73});

        //Rayures de la feuille
        window << nsShape::Line(nsGraphics::Vec2D(x,y-radius+radius/4),nsGraphics::Vec2D(x,y+3*radius/4),nsGraphics::RGBAcolor{76,34,12},2.f);
        for (unsigned y2=y-radius+2*radius/4; y2<y+3*radius/4 ;--y2){
            window << nsShape::Line (nsGraphics::Vec2D(x,y2),nsGraphics::Vec2D(x-size/2,y2-size/2),nsGraphics::RGBAcolor{76,34,12},1.f);
            window << nsShape::Line (nsGraphics::Vec2D(x,y2),nsGraphics::Vec2D(x+size/2,y2-size/2),nsGraphics::RGBAcolor{76,34,12},1.f);
            y2+=radius/4;
        }
        //Queue de la feuille
        window << nsShape::Line (nsGraphics::Vec2D(x,y+radius),nsGraphics::Vec2D(x,y+radius+size/2),nsGraphics::RGBAcolor{228,221,73},2.f);
    }
    //Bouclier en fin de vie
    else if(state==1){
        //Corps de la feuille
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x,y),radius,size,'l',nsGraphics::RGBAcolor{95,73,58});
        window << half_circle::Half_Circle(nsGraphics::Vec2D(x,y),radius,size,'r',nsGraphics::RGBAcolor{95,73,58});

        //Rayures de la feuille
        window << nsShape::Line(nsGraphics::Vec2D(x,y-radius+radius/4),nsGraphics::Vec2D(x,y+3*radius/4),nsGraphics::RGBAcolor{76,34,12},2.f);
        for (unsigned y2=y-radius+2*radius/4; y2<y+3*radius/4 ;--y2){
            window << nsShape::Line (nsGraphics::Vec2D(x,y2),nsGraphics::Vec2D(x-size/2,y2-size/2),nsGraphics::RGBAcolor{76,34,12},1.f);
            window << nsShape::Line (nsGraphics::Vec2D(x,y2),nsGraphics::Vec2D(x+size/2,y2-size/2),nsGraphics::RGBAcolor{76,34,12},1.f);
            y2+=radius/4;
        }
        //Queue de la feuille
        window << nsShape::Line (nsGraphics::Vec2D(x,y+radius),nsGraphics::Vec2D(x,y+radius+size/2),nsGraphics::RGBAcolor{95,73,58},2.f);

        //Trous de la feuille
        window <<nsShape::Circle(nsGraphics::Vec2D(x+2*size/3,y),size/2,nsGraphics::KBlack);
        window <<nsShape::Circle(nsGraphics::Vec2D(x-2*size/3,y-radius/3),size/3,nsGraphics::KBlack);
        window <<nsShape::Circle(nsGraphics::Vec2D(x-2*size/3,y+radius/3),size/3,nsGraphics::KBlack);
    }
}//draw()