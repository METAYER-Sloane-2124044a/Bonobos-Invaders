//
// Created by marius on 13/12/2021.
//

#include "game/scenes/multi.h"

using namespace std;

using namespace player;
using namespace torpedo;
using namespace startGame;
using namespace enemy;
using namespace waveManager;
using namespace shield;

std::vector<Torpedo> torpedos; //vecteur de toutes les torpilles
std::vector<Player> players; //Vecteur des joueurs
std::vector<StartGame> startgame; //Vecteur du lancement du jeu
std::vector<Enemy> enemies; //Vecteur des ennemies
std::vector<Shield> shields; //Vecteur des boucliers

std::map<std::string, std::string> configMapMulti;

bool isWave=false; //Savoir si il y a une wave e cours ou non

unsigned lastWave(0); //Numéro de la vague précédente
unsigned wave(0); //Numéro de la vague en cours (0 est en attente du start)
bool shieldActive (false); //Permet de savoir si un joueur à un bouclier
bool cameFromGetPseudo=true; //Permet de savoir si l'on vien de donner les pseudos

void multi::initConfig(std::map<std::string, std::string> &configMap) {
    configMapMulti=configMap;
}

void multi::init(MinGL &window) {
    //init du vecteur playeurs
    players.clear();
    players.emplace_back(0,window.getWindowSize().getY()/2,0);
    players.emplace_back(window.getWindowSize().getX(),window.getWindowSize().getY()/2,1);
    players[0].pos.setX(players[0].pos.getX()+players[0].size[1]);
    players[0].pos.setY(players[0].pos.getY());
    players[1].pos.setX(players[1].pos.getX()-players[1].size[1]);
    players[1].pos.setY(players[1].pos.getY());
    std::vector<unsigned> size {150,50};
    startgame.emplace_back(StartGame(window,size));
    players[0].pseudo=getPseudo::getPseudo()[0];
    players[1].pseudo=getPseudo::getPseudo()[1];
    //init des boucliers
    shields.clear();
    genShield(shields,window);
    shieldActive = false;
    //init des vagues d'enemies
    wave = 0;
    lastWave = 0;
    isWave = false;
}

vector<std::string> multi::getScore(){
    return {players[0].pseudo,players[1].pseudo,to_string(players[0].score),to_string(players[1].score)};
}

void multi::clearAll(MinGL &window){
    torpedos.clear();
    for (Shield &S: shields){
        S.life = 0;
    }
    //pour chaques joueurs, le remet en vie et a sa position initiale
    for (Player &p : players){
        p.pos.setY(window.getWindowSize().getY()/2);
        p.life=std::stoul(configMapMulti["playerLife"]);
    }
    enemies.clear();
}

unsigned multi::update(MinGL &window){
    if(cameFromGetPseudo){
        init(window);
        cameFromGetPseudo= false;
    }
    //Détection de changement de vague
    if (wave != lastWave){
        clearAll(window);
        enemies = loadWave(wave, window,configMapMulti);
        //Si pas d'ennemies, c'est qu'il n'y a plus de level donc fin
        if (enemies.size() == 0){
            score::highScoreWriter(players);
            highScore::init(configMapMulti);
            clearAll(window);

            isWave = false;
            cameFromGetPseudo=true;
            getPseudo::init(2);
            if (players[0].score>players[1].score) {
                return 5;
            }
            else {
                return 6;
            }
        }
        shieldActive = false;
        isWave= true;
    }
    lastWave = wave;
    //Gestion des entrées claviers
    if (window.isPressed({'z', false}) && players[0].pos.getY() > players[0].size[1]/2)
        players[0].pos.setY(players[0].pos.getY()-5);
    if (window.isPressed({'s', false}) && players[0].pos.getY() < window.getWindowSize().getY()-players[0].size[1]/2)
        players[0].pos.setY(players[0].pos.getY()+5);
    if (window.isPressed({'d', false}))
        players[0].shoot(1,1,torpedos);
    if (window.isPressed({GLUT_KEY_UP, true}) && players[1].pos.getY() > players[1].size[1]/2)
        players[1].pos.setY(players[1].pos.getY()-5);
    if (window.isPressed({GLUT_KEY_DOWN, true}) && players[1].pos.getY() < window.getWindowSize().getY()-players[1].size[1]/2)
        players[1].pos.setY(players[1].pos.getY()+5);
    if (window.isPressed({GLUT_KEY_LEFT, true}))
        players[1].shoot(2,0,torpedos);
    for (unsigned i(0); i < torpedos.size(); ++i){
        torpedos[i].update();
        if (torpedos[i].pos.getX() < 0 || torpedos[i].pos.getX() > window.getWindowSize().getX())
            torpedos.erase(torpedos.begin()+i);
    }

    //Mise à jour des joueurs
    for (Player &P : players){
        P.update();
        if (P.life<=0)
            ++wave;
    }
    std::vector<unsigned> enemiesSup;
    unsigned cpt=0;
    for (Enemy &E : enemies){
        E.update(enemies, torpedos,window);   //on met a jour les invaders
        if (E.pos.getX()<players[0].size[0]*2) {
            enemiesSup.push_back(cpt); //on compte les invaders qui ont dépassé le camp
            if (E.alive)
                --players[0].life;
        }
        else if (E.pos.getX()>window.getWindowSize().getX()-players[1].size[0]*2) {
            enemiesSup.push_back(cpt);
            if (E.alive)
                --players[1].life;
        }
        ++cpt;
    }
    for (unsigned i:enemiesSup)       //on suprime les invaders qui ont dépassé le camp allié
        enemies.erase(enemies.begin() + i);

    //Gestion des collisions
    std::vector<std::vector<char>> returnVec;
    collision::genColl(torpedos, players);
    returnVec = collision::collision(players,torpedos,enemies,shields,startgame);

    for (std::vector<char> collide : returnVec){
        switch (collide[0]) {
            case 't':
                switch (collide[2]) {
                    case 'p':
                        if (collide[4] == 1){
                            //torpille à touché joueur 1
                            --players[1].life;
                            if (collide[1] != 0) score::scorePlayer(players[0]);
                        }
                        else{
                            //torpille à touché joueur 2
                            --players[0].life;
                            if (collide[1] != 0) score::scorePlayer(players[1]);
                        }
                        break;
                    case 'e':
                        //torpille à touché un enemie
                        score::scoreInvader(collide[1],enemies[collide[3]],players);
                        enemies[collide[3]].alive = false;
                        //Activation du bouclier si nessecaire
                        if (not shieldActive){
                            if (not chekEnemiesInLive(enemies,'g')) {
                                for (unsigned i(0); i < shields.size() / 2; ++i) {
                                    shields[i].life = 3;
                                    shieldActive = true;
                                }
                            }
                            if (not chekEnemiesInLive(enemies,'d')) {
                                for (unsigned i(shields.size()/2); i < shields.size(); ++i) {
                                    shields[i].life = 3;
                                    shieldActive = true;
                                }
                            }
                        }
                        break;
                }
                break;
            //collision entre joueur et enemies
            case 'p':
                enemies[collide[2]].alive = false;
                break;
            //collision entre une torpille et le start
            case 's':
                startgame.clear();
                wave = 1;
                isWave=true;
                break;
        }
    }

    if (isWave && not chekEnemiesInLive(enemies,'g') && not chekEnemiesInLive(enemies, 'd')){   //Mort subite quand y a plus d'enemies
        for(Player &P : players){
            P.life = 1;
            P.pos.setY(window.getWindowSize().getY()/2);
        }
        torpedos.clear();
        isWave= false;
    }

    return 1;
} //unsigned multi::update(MinGL &window)

void multi::render(MinGL &window, nsGui::Sprite &background) {
    window << background;
    for (Player &P: players) {
        P.show(window);
    }
    for (Torpedo &T: torpedos) {
        T.show(window);
    }
    if (wave == 0) {
        for (StartGame &SG: startgame) {
            SG.show(window);
        }
    }
    for (Enemy &E: enemies) {
        if (E.alive) E.show(window);
    }
    for (Shield &S: shields){
        if(S.life > 0) S.show(window);
    }

    window << score::showScore(players, window);
    unsigned lifeSizeMulti=stoul(configMapMulti["playerLifeSize"]);
    players[0].showLife(window,nsGraphics::Vec2D(6*lifeSizeMulti,20+6*lifeSizeMulti));
    players[1].showLife(window,nsGraphics::Vec2D(1366-18*lifeSizeMulti,20+6*lifeSizeMulti));
}