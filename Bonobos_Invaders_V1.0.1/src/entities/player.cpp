//
// Created by marius on 14/12/2021.
//

#include "game/entities/player.h"

unsigned sizeXP,sizeYP,lifeP,shootLim,lifeSize;

void player::init(std::map<std::string,std::string> &configMap){
    sizeXP=stoul(configMap["playerSizeX"]);
    sizeYP=stoul(configMap["playerSizeY"]);
    lifeP=stoul(configMap["playerLife"]);
    shootLim=stoul(configMap["playerShootLimit"]);
    lifeSize=stoul(configMap["playerLifeSize"]);
}

player::Player::Player(int entX, int entY, unsigned entId) {
    pos = nsGraphics::Vec2D(entX,entY);
    size = {sizeXP,sizeYP};
    life = lifeP;
    shootLimit = shootLim;
    shootCount = 0;
    id = entId;
    score=0;
    pseudo="aaaa";
}

void player::Player::shoot(unsigned from, unsigned to, std::vector<torpedo::Torpedo> &torpedos) {
    // Si le joueur peut, tir
    if (shootCount == 0){
        if (id == 0)
            torpedos.emplace_back(from,to,pos.getX()+size[0]/2+1,pos.getY());
        else
            torpedos.emplace_back(from,to,pos.getX()-size[0]/2-1,pos.getY());
        shootCount = shootLimit;
    }
}

void player::Player::update() {
    if (shootCount > 0)
        -- shootCount;
}

void player::Player::show(MinGL &window) {
    bonobo::draw(window,pos,size[0]/2);
}

void player::Player::showLife(MinGL &window, nsGraphics::Vec2D pos){
    if (life>=1)
        life::draw(window,pos,lifeSize);
    if (life>=2)
        life::draw(window, nsGraphics::Vec2D(pos.getX() + lifeSize*6, pos.getY()), lifeSize);
    if (life>=3)
        life::draw(window, nsGraphics::Vec2D(pos.getX() + lifeSize*12, pos.getY()), lifeSize);
}