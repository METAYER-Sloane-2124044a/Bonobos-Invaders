//
// Created by marius on 21/12/2021.
//

#include "game/entities/enemy.h"

unsigned sizeX,sizeY;

void enemy::init(std::map<std::string,std::string> &configMap){
    sizeX = stoul(configMap["enemySizeX"]);
    sizeY = stoul(configMap["enemySizeY"]);
}

enemy::Enemy::Enemy(nsGraphics::Vec2D entPos, char entWay) {
    pos = entPos;
    size = {sizeX,sizeY};
    way = entWay;
    srand(time(NULL));
}

void enemy::Enemy::update(std::vector<Enemy> &enemies, std::vector<torpedo::Torpedo> &torpedos, MinGL &window) {
    //Gestion du déplacement
    if (goDown){
        pos.setY(pos.getY()+1);
        //Si on touche le bords de l'écran tous les enemies qui vont dans la même sens (gauche-droite) change de sens (haut-bas)
        if (pos.getY()+size[1]/2 >= window.getWindowSize().getY())
            for (Enemy &enemy: enemies) {
                if (way == enemy.way) {
                    enemy.goDown = false;
                    if (way == 'g') {
                        enemy.pos.setX(enemy.pos.getX() - 50);
                    } else {
                        enemy.pos.setX(enemy.pos.getX() + 50);
                    }
                }
            }
    }
    else{
        pos.setY(pos.getY()-1);
        //Si on touche le bords de l'écran tous les enemies qui vont dans la même sens (gauche-droite) change de sens (haut-bas)
        if (pos.getY()-size[1]/2 <= 0){
            for (Enemy &enemy : enemies){
                if (way == enemy.way) {
                    enemy.goDown = true;
                    if (way == 'g')
                        enemy.pos.setX(enemy.pos.getX() - 50);
                    else
                        enemy.pos.setX(enemy.pos.getX() + 50);
                }
            }
        }
    }

    //1/400 de tirer une torpilles
    if (alive && rand()%400 <= 1){
        if (way == 'g') torpedos.emplace_back(0,0,pos.getX()-(size[0]/2)-50,pos.getY());
        else torpedos.emplace_back(0,1,pos.getX()+(size[0]/2)+50,pos.getY());
    }
}


void enemy::Enemy::show(MinGL &window) {
    baobab::draw(window,pos,size[0]);
}