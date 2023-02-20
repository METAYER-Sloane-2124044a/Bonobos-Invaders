//
// Created by marius on 03/01/2022.
//

#include "game/entities/shield.h"

shield::Shield::Shield(const nsGraphics::Vec2D &entPos) {
    pos = entPos;
    life = 0;
}

void shield::Shield::show(MinGL &window) {
    shield::draw(window,pos,40,15,life);
}

void shield::genShield(std::vector<shield::Shield> &shields, MinGL &window){
    unsigned div3 = window.getWindowSize().getY()/5;
    shields.emplace_back(nsGraphics::Vec2D(150,div3));
    shields.emplace_back(nsGraphics::Vec2D(150,window.getWindowSize().getY()/2));
    shields.emplace_back(nsGraphics::Vec2D(150,window.getWindowSize().getY()-div3));

    shields.emplace_back(nsGraphics::Vec2D(window.getWindowSize().getX()-150,div3));
    shields.emplace_back(nsGraphics::Vec2D(window.getWindowSize().getX()-150,window.getWindowSize().getY()/2));
    shields.emplace_back(nsGraphics::Vec2D(window.getWindowSize().getX()-150,window.getWindowSize().getY()-div3));
}