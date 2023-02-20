//
// Created by marius on 23/12/2021.
//

#include "game/waveManager/waveManager.h"

std::vector<unsigned> enemySize;

std::vector<enemy::Enemy> waveManager::loadWave(unsigned int &nb, MinGL &window,std::map<std::string,std::string> &configMap) {
    //Création du fichier par rapport au nombre de la vague
    std::string path = configMap["levelPath"]+"/level" + std::to_string(nb) + ".lvl";
    //Marque un temps d'attente
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    std::ifstream ifs(path);
    std::string line;
    std::vector<enemy::Enemy> enemies;
    unsigned cpt(1);
    //Pour chaque lignes du fichier, si on trouve un X, on ajoutte un enemies
    while (getline(ifs, line)){
        unsigned numberOfEnemies = line.size();
        for (unsigned i(0); i < numberOfEnemies; ++i) {
            if (line[i] == 'X'){
                enemies.emplace_back(nsGraphics::Vec2D(window.getWindowSize().getX()/2 - enemySize[0] * cpt, enemySize[1] + (enemySize[1]*i)),'g');
                enemies.emplace_back(nsGraphics::Vec2D(window.getWindowSize().getX()/2 + enemySize[0] * cpt, enemySize[1] + (enemySize[1]*i)),'d');
            }
        }
        ++cpt;
    }
    return enemies;
}

void waveManager::initEnemies (std::map<std::string,std::string> configMap){
    enemySize.push_back(stoul(configMap["enemySizeX"]));
    enemySize.push_back(stoul(configMap["enemySizeY"]));
}

bool waveManager::chekEnemiesInLive(std::vector<enemy::Enemy> &enemies, char player){
    for (enemy::Enemy &E : enemies){
        if (E.way == player && E.alive) return true;
    }
    return false;
}