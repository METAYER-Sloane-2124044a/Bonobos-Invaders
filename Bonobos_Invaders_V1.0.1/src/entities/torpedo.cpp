#include "game/entities/torpedo.h"

unsigned sizeXT,sizeYT,speedLim;

void torpedo::init(std::map<std::string,std::string> &configMap){
    sizeXT=stoul(configMap["torpedoSizeX"]);
    sizeYT=stoul(configMap["torpedoSizeY"]);
    speedLim=stoul(configMap["torpedoSpeedLimit"]);
}

torpedo::Torpedo::Torpedo(unsigned entFrom, unsigned entTo, int entPosX, int entPosY) {
    from=entFrom;
    to=entTo;
    pos=nsGraphics::Vec2D (entPosX,entPosY);
    size = {sizeXT,sizeYT};
    speedLimit = speedLim;
    speedCount = 0;
}

void torpedo::Torpedo::update() {
    //Si la limite de déplacement n'est pas dépassée, on effectue le mouvement suivant la direction
    if (speedCount == 0){
        switch (to) {
            case 0:
                pos.setX(pos.getX()-10);
                speedCount = speedLimit;
                break;
            case 1:
                pos.setX(pos.getX()+10);
                speedCount = speedLimit;
                break;
        }
    }
    else
        --speedCount;
}

void torpedo::Torpedo::show(MinGL &window){
    if (from == 0) branch::draw(window,pos,size[0]);
    else {
        if (to == 0) banana::draw(window,pos,size[0],'l');
        else banana::draw(window,pos,size[0],'r');
    }
}