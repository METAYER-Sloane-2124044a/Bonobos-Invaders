/**
 * @file    menu.h
 * @author  Marius PISTORESI
 * @date    Decembre 2021
 * @version 1.0
 * @brief   Scène du menu
 **/

#include <fstream>

#include "mingl/mingl.h"
#include "mingl/gui/text.h"
#include "mingl/shape/rectangle.h"

#include "game/yaml/configReader.h"
#include "mingl/gui/sprite.h"

#include "game/graphic/exit_button.h"
#include "game/graphic/credit_button.h"
#include "game/graphic/highscore_button.h"
#include "game/graphic/play_button.h"
#include <cstdlib>

#ifndef S102_MENU_H
#define S102_MENU_H

namespace menu{

    /**
     * @brief Initialisaition de la scène
     * @param[in] configMap : map de la configuration
     * @param[in] background : L'image de son background
     * @fn init(std::map<std::string,std::string> &configMap, nsGui::Sprite &background)
     */
    void init(std::map<std::string,std::string> &configMap, nsGui::Sprite &background);

    /**
    * @brief Permet de traiter les entrées claviers de l'utilisateur
    * @param[in,out] window : fenêtre du jeu de type MinGL
    * @return unsigned : 2,3,4 pour la prochaine scène espérée, ou fermeture de la fenêtre complète
    * @fn update(MinGL &window)
    */
    unsigned update(MinGL &window);

    /**
     * @brief Permet d'afficher le bouton de lancement d'une partie
     * @param[in,out] window : fenêtre de jeu
     * @fn showMultiButton(MinGL &window)
     */
    void showMultiButton(MinGL &window);

    /**
     * @brief Permet d'afficher le bouton pour acceder au high score
     * @param[in,out] window : fenêtre de jeu
     * @fn showHighScore(MinGL &window)
     */
    void showHighScore(MinGL &window);

    /**
     * @brief Permet d'afficher le bouton pour acceder au crédits
     * @param[in,out] window : fenêtre de jeu
     * @fn showCreditButton(MinGL &window)
     */
    void showCreditButton(MinGL &window);

    /**
     * @brief Permet d'afficher le bouton pour quitter le jeu
     * @param[in,out] window : fenêtre de jeu
     * @fn showExitButton(MinGL &window)
     */
    void showExitButton(MinGL &window);

    /**
     * @brief Permet de générer graphiquement la version du jeu
     * @param[in] window : fenêtre de jeu
     * @return nsGui::Text : Le texte de la version du jeu
     * @fn showVersion(MinGL &window)
     */
    nsGui::Text showVersion(MinGL &window);
    /**
     * @brief Permet d'injecter le flux de la scène de la fenêtre de jeu
     * @param[in,out] window : fenêtre de jeu
     * @fn render(MinGL &window)
     */
    void render(MinGL &window);
}

#endif //S102_MENU_H
