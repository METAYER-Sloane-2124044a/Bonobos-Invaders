//
// Created by marius on 14/12/2021.
//

#include "game/collision/collision.h"

using namespace player;
using namespace torpedo;
using namespace enemy;
using namespace shield;

std::vector<std::vector<nsGraphics::Vec2D>> collTorpedo;
std::vector<std::vector<nsGraphics::Vec2D>> collPlayer;

void collision::genColl(std::vector<Torpedo> &T, std::vector<Player> &P){
    // Permet d'éviter les doublons
    collTorpedo.clear();
    // On défénit 2 points par torpilles, un au coins au haut et l'autre en bas (la direction est par rapport au sens de la torpille)
    for (Torpedo &torpedo : T){
        std::vector<nsGraphics::Vec2D> tmp(2);
        switch (torpedo.to){
            case 0:
                tmp[0].setX(torpedo.pos.getX()-torpedo.size[0]/2);
                tmp[0].setY(torpedo.pos.getY()-torpedo.size[1]/2);
                tmp[1].setX(torpedo.pos.getX()-torpedo.size[0]/2);
                tmp[1].setY(torpedo.pos.getY()+torpedo.size[1]/2);
                break;
            case 1:
                tmp[0].setX(torpedo.pos.getX()+torpedo.size[0]/2);
                tmp[0].setY(torpedo.pos.getY()-torpedo.size[1]/2);
                tmp[1].setX(torpedo.pos.getX()+torpedo.size[0]/2);
                tmp[1].setY(torpedo.pos.getY()+torpedo.size[1]/2);
                break;
        }
        collTorpedo.push_back(tmp);
    }

    // On défénit 2 points par joueurs, un au coins au haut et l'autre en bas (la direction est par rapport au côté du joueur)
    collPlayer.clear();
    for(Player &player : P){
        std::vector<nsGraphics::Vec2D> tmp(2);
        switch (player.id){
            case 0:
                tmp[0].setX(player.pos.getX()+player.size[0]/2);
                tmp[0].setY(player.pos.getY()-player.size[1]/2);
                tmp[1].setX(player.pos.getX()+player.size[0]/2);
                tmp[1].setY(player.pos.getY()+player.size[1]/2);
                break;
            case 1:
                tmp[0].setX(player.pos.getX()-player.size[0]/2);
                tmp[0].setY(player.pos.getY()-player.size[1]/2);
                tmp[1].setX(player.pos.getX()-player.size[0]/2);
                tmp[1].setY(player.pos.getY()+player.size[1]/2);
                break;
        }
        collPlayer.push_back(tmp);
    }
}

bool collision::isColliding(nsGraphics::Vec2D &pos, nsGraphics::Vec2D &firstCorner, nsGraphics::Vec2D &secondCorner){
    bool collidingX (false);
    bool collidingY (false);

    //Vérification de la collision entre la coordonée X de pos et les coins
    if (firstCorner.getX() < secondCorner.getX() && firstCorner.getX() <= pos.getX() && pos.getX() <= secondCorner.getX()){
        collidingX = true;
    }
    else if (secondCorner.getX() <= pos.getX() && pos.getX() <= firstCorner.getX()){
        collidingX = true;
    }
    //Si il y a collision X : Vérification de la collision entre coordonée Y de pos et les coins
    if (collidingX){
        if (firstCorner.getY() < secondCorner.getY() && firstCorner.getY() <= pos.getY() && pos.getY() <= secondCorner.getY()){
            collidingY = true;
        }
        else if (secondCorner.getY() <= pos.getY() && pos.getY() <= firstCorner.getY()){
            collidingY = true;
        }
    }
    // Si collidingY est vrai, collidingX aussi donc il y a collision
    return collidingY;
}

void collision::supDouble(std::vector<unsigned> &vec){
    //Si une valeur est égal à la suivante, alors, elle est suprimée et on ne change pas de place sinon on passe à la case suivante
    unsigned i(0);
    if (vec.size() != 0){
        while (i < vec.size()-1){
            if (vec[i] == vec[i+1]){
                vec.erase(vec.begin()+i+1);
            }
            else
                ++i;
        }
    }
}

std::vector<std::vector<char>> collision::collision(std::vector<player::Player> &players, std::vector<torpedo::Torpedo> &torpedos, std::vector<enemy::Enemy> &enemies, std::vector<shield::Shield> &shields,std::vector<startGame::StartGame> &startGame){
    unsigned cpt(0);
    std::vector<std::vector<char>> returnVec;
    std::vector<unsigned> torpedosToSupp;
    std::vector<unsigned> enemiesToSupp;

    //Vérification des torpilles
    for (unsigned i(0); i < collTorpedo.size(); ++i) {
        //Avec les torpilles
        for (unsigned j(0); j < collTorpedo.size(); ++j){
            //Passage des coins en variables
            nsGraphics::Vec2D firstCorner(torpedos[j].pos.getX()-torpedos[j].size[0]/2,torpedos[j].pos.getY()-torpedos[j].size[1]/2);
            nsGraphics::Vec2D secondCorner(torpedos[j].pos.getX()+torpedos[j].size[0]/2,torpedos[j].pos.getY()+torpedos[j].size[1]/2);
            //Vérification de la collision
            if (i != j && (isColliding(collTorpedo[i][0],firstCorner,secondCorner) || isColliding(collTorpedo[i][1],firstCorner, secondCorner))){
                torpedosToSupp.push_back(j);
                torpedosToSupp.push_back(i);
            }
        }

        //Vérification des joueurs
        for (unsigned j(0); j < players.size(); ++j){
            //Passage des coins en variables
            nsGraphics::Vec2D firstCorner(players[j].pos.getX()-players[j].size[0]/2,players[j].pos.getY()-players[j].size[1]/2);
            nsGraphics::Vec2D secondCorner(players[j].pos.getX()+players[j].size[0]/2,players[j].pos.getY()+players[j].size[1]/2);
            //Vérification de la collision
            if (isColliding(collTorpedo[i][0],firstCorner,secondCorner) || isColliding(collTorpedo[i][1],firstCorner,secondCorner)){
                torpedosToSupp.push_back(i);
                returnVec.push_back({'t', char(torpedos[i].from),'p', char(j),char(torpedos[i].to)});
            }
        }

        //Vérification des ennemies
        for (unsigned j(0); j < enemies.size(); ++j){
            if (enemies[j].alive && torpedos[i].from != 0) {
                //Passage des coins en variables
                nsGraphics::Vec2D firstCorner(enemies[j].pos.getX() - enemies[j].size[0] / 2,enemies[j].pos.getY() - enemies[j].size[1] / 2);
                nsGraphics::Vec2D secondCorner(enemies[j].pos.getX() + enemies[j].size[0] / 2,enemies[j].pos.getY() + enemies[j].size[1] / 2);
                //Vérification de la collision
                if (isColliding(collTorpedo[i][0], firstCorner, secondCorner) ||
                    isColliding(collTorpedo[i][1], firstCorner, secondCorner)) {
                    torpedosToSupp.push_back(i);
                    enemiesToSupp.push_back(j);
                    returnVec.push_back({'t', char(torpedos[i].from),'e', char(j),char(torpedos[i].to)});
                }
            }
        }

        //Vérification avec les boucliers
        for (unsigned j(0); j < shields.size(); ++j){
            if (shields[j].life > 0){
                //Passage des coins en variables
                nsGraphics::Vec2D firstCorner(shields[j].pos.getX()-30,shields[j].pos.getY()-30);
                nsGraphics::Vec2D secondCorner(shields[j].pos.getX()+30,shields[j].pos.getY()+30);
                //Vérification de la collision
                if (isColliding(collTorpedo[i][0],firstCorner,secondCorner) || isColliding(collTorpedo[i][1],firstCorner,secondCorner)){
                    torpedosToSupp.push_back(i);
                    shields[j].life -= 1;
                }
            }
        }

        //Vérification avec le start
        for (unsigned j(0); j < startGame.size(); ++j){
            //Passage des coins en variables
            nsGraphics::Vec2D firstCorner(startGame[j].pos.getX()-startGame[j].size[0]/2, startGame[j].pos.getY()-startGame[j].size[1]/2);
            nsGraphics::Vec2D secondCorner(startGame[j].pos.getX()+startGame[j].size[0]/2, startGame[j].pos.getY()+startGame[j].size[1]/2);
            //Vérification de la collision
            if (isColliding(collTorpedo[i][0],firstCorner,secondCorner) || isColliding(collTorpedo[i][1],firstCorner,secondCorner)){
                torpedosToSupp.push_back(i);
                returnVec.push_back({'s'});
            }
        }
    }

    //Vérification des collisions entre joueurs et enemies
    for (unsigned i(0); i < players.size(); ++i){
        for (unsigned j(0); j < enemies.size(); ++j){
            if (enemies[j].alive) {
                //Passage des coins en variables
                nsGraphics::Vec2D firstCorner(enemies[j].pos.getX() - enemies[j].size[0] / 2,enemies[j].pos.getY() - enemies[j].size[1] / 2);
                nsGraphics::Vec2D secondCorner(enemies[j].pos.getX() + enemies[j].size[0] / 2,enemies[j].pos.getY() + enemies[j].size[1] / 2);
                //Vérification de la collision
                if (isColliding(collPlayer[i][0], firstCorner, secondCorner) ||
                    isColliding(collPlayer[i][1], firstCorner, secondCorner)) {
                    enemiesToSupp.push_back(j);
                    returnVec.push_back({'p', char(i), char(j)});
                }
            }
        }
    }

    //Tri du tableau et suppression des doublons du veteur de suppression de torpilles
    std::sort(torpedosToSupp.begin(), torpedosToSupp.end());
    supDouble(torpedosToSupp);

    //Sression des torpilles
    if (torpedosToSupp.size() != 0) {
        for (unsigned val: torpedosToSupp) {
            torpedos.erase(torpedos.begin() + val - cpt);
            ++cpt;
        }
    }

    //Tri du tableau et suppression des doublons du veteur de suppression des ennemies
    std::sort(enemiesToSupp.begin(), enemiesToSupp.end());
    supDouble(enemiesToSupp);

    return returnVec;
}
