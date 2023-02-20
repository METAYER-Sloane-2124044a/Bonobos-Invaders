/**
 * @file    winningScreen.h
 * @author  Alexis MARIOTTI
 * @date    Janvier 2021
 * @version 1.0
 * @brief   Scene de victoire/defaite
 **/

#include "multi.h"
#include <thread>

#ifndef S102_WINNINGSCREEN_H
#define S102_WINNINGSCREEN_H

namespace winningScreen {
    /**
      * @brief Initialisation à partir du fichier config
      * @param configMap[in] : map généré a partir du fichier de configuration
      * @fn init(std::map<std::string,std::string> &configMap)
      */
    void init(std::map<std::string,std::string> &configMap);

    /**
      * @brief Permet d'attendre le temps donné pour cette scene, et permet de renvoyé la valeur pour la scene gauche
      * @param[in] window : fenêtre de jeu
      * @param[in] count : valleur qui permet de savoir à quelle frame de cette scene nous sommes
      * @return unsigned : La prochaine scene que le main va devoir traiter
      * @fn updateLeft(MinGL &window,unsigned &count)
      */
    unsigned updateLeft(MinGL &window,unsigned &count);
    /**
      * @brief Permet d'attendre le temps donné pour cette scene, et permet de renvoyé la valeur pour la scene droite
      * @param[in] window : fenêtre de jeu
      * @param[in] count : valleur qui permet de savoir à quelle frame de cette scene nous sommes
      * @return unsigned : La prochaine scene que le main va devoir traiter
      * @fn updateRigth(MinGL &window,unsigned &count)
      */
    unsigned updateRigth(MinGL &window,unsigned &count);
    /**
     * @brief Permet d'injecter le flux de la scene dans la fenêtre de jeu quand le joueur de gauche gagne
     * @param [in-out]window : La fênetre de jeu
     * @param [in]background : Le fond de la scene
     * @fn renderLeft(MinGL &window, nsGui::Sprite &background)
     */
    void renderLeft(MinGL &window, nsGui::Sprite &background);

        /**
     * @brief Permet d'injecter le flux de la scene dans la fenêtre de jeu quand le joueur de droite gagne
     * @param [in-out]window : La fênetre de jeu
     * @param [in]background : Le fond de la scene
     * @fn renderRight(MinGL &window, nsGui::Sprite &background)
     */
    void renderRight(MinGL &window, nsGui::Sprite &background);
}
#endif //S102_WINNINGSCREEN_H
