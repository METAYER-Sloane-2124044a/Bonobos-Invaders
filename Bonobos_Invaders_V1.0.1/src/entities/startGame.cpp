//
// Created by marius on 21/12/2021.
//

#include "game/entities/startGame.h"

startGame::StartGame::StartGame(MinGL &window, std::vector<unsigned int> &entSize) {
    pos = nsGraphics::Vec2D(window.getWindowSize().getX()/2,window.getWindowSize().getY()/2);
    size = entSize;
}

void startGame::StartGame::show(MinGL &window){
    start_button::draw(window,pos,size[0]-30);
}