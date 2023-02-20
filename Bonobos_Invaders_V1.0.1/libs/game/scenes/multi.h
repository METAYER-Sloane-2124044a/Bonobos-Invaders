/**
 * @file    multi.h
 * @author  Alexis MARIOTTI | Marius PISTORESI
 * @date    Janvier 2021
 * @version 1.0
 * @brief   Gestion du mode de jeu multi
 **/


#include "game/scenes/getPseudo.h"
#include "game/entities/startGame.h"
#include "game/score/score.h"
#include "game/collision/collision.h"
#include "game/waveManager/waveManager.h"
#include "game/entities/shield.h"


#include "mingl/gui/sprite.h"
#include "game/scenes/highScore.h"

#ifndef S102_MULTI_H
#define S102_MULTI_H

namespace multi{
    /**
     * @brief Initialisation du dictionaire de config avec celui créé à partir du ficher config
     * @param[in] configMap : Le dictionaire, rempli à partir du fichier de config
     * @fn initConfig(std::map<std::string, std::string> &configMap)
     */
    void initConfig(std::map<std::string, std::string> &configMap);
    /**
     * @brief Initialisation de la fenêtre multi et génération des entitées
     * @param{in] window : La fenetre de jeu
     * @fn init(MinGL &window)
     */
    void init(MinGL &window);

    /**
     * @brief Permet de récupérer le score et le nom des joueurs
     * @return std::vector<std::string> : pseudo1, pseudo2, score1, score2
     * @fn getScore()
     */
    std::vector<std::string> getScore();

    /**
     * @brief Enleève toutes le entitiées présente dans le jeu et remet les joueurs en place
     * @param[in] window : La fênetre de jeu
     * @fn clearAll(MinGL &window)
     */
    void clearAll(MinGL &window);

    /**
     * @brief Permet de traiter les entrées claviers des joueurs, les collisions et les vagues
     * @param[in] window : fenêtre de jeu
     * @fn update(MinGL &window)
     */
    unsigned update(MinGL &window);

    /**
     * @brief Permet d'injecter le flux de la scene dans la fenêtre de jeu
     * @param[in,out] window : fênetre de jeu
     * @param [in] background : Le fond du jeu
     * @fn render(MinGL &window, nsGui::Sprite &background)
     */
    void render(MinGL &window, nsGui::Sprite &background);
}

#endif //S102_MULTI_H
