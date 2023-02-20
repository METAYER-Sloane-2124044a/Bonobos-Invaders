/**
 * @file    highScore.h
 * @author  Alexis MARIOTTI |Marius PISTORESI
 * @date    Janvier 2022
 * @version 1.0
 * @brief   Scène du high score
 **/

#include "mingl/mingl.h"

#include "game/yaml/configReader.h"
#include "game/score/score.h"
#include "mingl/gui/sprite.h"

#ifndef S102_HIGHSCORE_H
#define S102_HIGHSCORE_H

namespace highScore{

    /**
     * @brief Mise en place de la configuration dans l'espace vide et la lecture du score board
     * @param[in] configMap : map de la configuration
     * @fn init(std::map<std::string,std::string> &configMap)
     */
    void init(std::map<std::string,std::string> &configMap);

    /**
     * @brief Gestion des entrées claviers
     * @param[in] window : fenêtre de jeu
     * @return unsigned : prochaine scène
     * @fn update(MinGL &window)
     */
    unsigned update(MinGL &window);

    /**
     * @brief Permet d'injecter le flux de la scène dans la fenêtre de jeu
     * @param[in,out] window : fenêtre du jeu
     * @param[in] background : le fond de la scène
     * @fn render(MinGL &window)
     */
    void render(MinGL &window, nsGui::Sprite &background);
}

#endif //S102_HIGHSCORE_H
