/**
 * @file    waveManager.h
 * @author  Marius PISTORESI
 * @date    Janvier 2022
 * @version 1.0
 * @brief   Gestion des vagues
 **/

#include <thread>
#include <chrono>
#include <fstream>

#include "game/entities/enemy.h"

#ifndef S102_WAVEMANAGER_H
#define S102_WAVEMANAGER_H

namespace waveManager {

    /**
<<<<<<< Updated upstream
     * @brief Permet de charger la vague
     * @param[in] nb : numéro de la vague
     * @param[in] window : fenêtre de jeu
     * @return std::vector<enemy::Enemy> : Vecteur des enemies
     * @fn loadWave(unsigned &nb, MinGL &window)
=======
     * @brief Charge la vague
     * @param nb : numéro de la vagueZ
     * @param mult : booléen de si nous sommes en multi
     * @return std::vector<enemy::Enemy>
>>>>>>> Stashed changes
     */
    std::vector<enemy::Enemy> loadWave(unsigned &nb, MinGL &window,std::map<std::string,std::string> &configMap);

    /**
     * @brief Initialisation de la scène avec le fichier de config
     * @param[in] configMap : map de la configuratio
     * @fn initEnemies (std::map<std::string,std::string> configMap)
     */
    void initEnemies (std::map<std::string,std::string> configMap);

    /**
     * @brief Prédicat de vérification de présence d'ennemies pour un joueur
     * @param[in] enemies : vecteurs des ennemies
     * @return bool : true si il reste des ennemies faux sinon
     */
    bool chekEnemiesInLive(std::vector<enemy::Enemy> &enemies, char player);
}
#endif //S102_WAVEMANAGER_H
