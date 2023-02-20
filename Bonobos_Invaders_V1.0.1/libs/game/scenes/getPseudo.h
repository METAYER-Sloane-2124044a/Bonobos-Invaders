/**
 * @file    getPseudo.h
 * @author  Alexis MARIOTTI
 * @date    Janvier 2022
 * @version 1.0
 * @brief   Scene du choix des pseudos
 **/
#include "mingl/gui/text.h"

#include "game/entities/player.h"
#include "mingl/gui/sprite.h"

#ifndef S102_GETPSEUDO_H
#define S102_GETPSEUDO_H

namespace getPseudo{
    /**
     * @brief Innitialise la scene
     * @param[in,out] number : le nombre de pseudos a demander
     * @fn init(std::vector<player::Player> &players)
     */
    void init(unsigned number);
    /**
     * @brief Permet de traiter les entrées claviers des joueurs
     * @param[in,out] window : fenêtre de jeu
     * @return unsigned : 1 pour aller sur la scene du multi quand les pseudos sont rentré, sinon 4
     * @fn update(MinGL &window)
     */
    unsigned update(MinGL &window);
    /**
     * @brief Permet d'injecter le flux la scene dans la fenêtre de jeu
     * @param window[in,out] : La fenêtre de jeu
     * @param background[in,out] : Le fond de la scene
     * @fn void render(MinGL &window, nsGui::Sprite &background)
     */
    void render(MinGL &window, nsGui::Sprite &background);
    /**
     * @brief fonction qui renvoie les pseudos
     * @return std::vector<std::string> : Vecteur contenant les pseudos des joeurs
     * @fn getPseudo()
     */
    std::vector<std::string> getPseudo();
}

#endif //S102_GETPSEUDO_H
