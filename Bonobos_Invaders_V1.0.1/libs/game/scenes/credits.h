/**
 * @file    credits.h
 * @author  Alexis MARIOTTI
 * @date    Décembre 2021
 * @version 1.0
 * @brief   Scene des credits
 **/

#include "mingl/mingl.h"
#include "mingl/gui/text.h"
#include "game/yaml/configReader.h"
#include "mingl/gui/sprite.h"

#ifndef S102_CREDITS_H
#define S102_CREDITS_H

namespace credits{

    /**
     * @brief Permet de revenir sur la scene menu quand on presse entrée
     * @param[in,out] window : fenêtre de jeu
     * @return unsigned : 2 pour la scene actuelle ou 0 pour le menu
     * @fn update(MinGL &window)
     */
    unsigned update(MinGL &window);

    /**
     * @brief Permet d'injecter le flux de la scene dans la fenêtre de jeu
     * @param[in,out] window : fenêtre de jeu
     * @fn render(MinGL &window)
     */
    void render(MinGL &window, nsGui::Sprite &background);
}


#endif //S102_CREDITS_H
