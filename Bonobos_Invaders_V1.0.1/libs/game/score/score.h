/**
 * @file    score.h
 * @author  Alexis MARIOTTI
 * @date    Decembre 2021
 * @version 1.0
 * @brief   gestion du score des joueurs
 **/

#include <fstream>
#include <algorithm>

#include "mingl/gui/text.h"

#include "game/entities/enemy.h"
#include "game/entities/player.h"
#include "game/entities/torpedo.h"

#ifndef S102_SCORE_H
#define S102_SCORE_H

namespace score{
    /**
      * @brief Initialisation à partir du fichier config
      * @param[in] configMap : map généré a partir du fichier de configuration
      * @fn init(std::map<std::string,std::string> &configMap)
      */
    void init(std::map<std::string,std::string> &configMap);

    /**
     * @brief: Procedure qui ajoute du score au joueur qui a tiré la torpedo selon la distance qu'elle a parcouru avant de toucher l'invader
     * @param[in] from : de qui vien la torpille
     * @param[in,out] players : le vecteur de joueurs
     * @param[in] enemy : l'invader qui a été touché par la torpille
     * @fn scoreInvader(unsigned from,enemy::Enemy &enemy, std::vector<player::Player> &players)
     */
    void scoreInvader(unsigned from,enemy::Enemy &enemy, std::vector<player::Player> &players);
    /**
     * @brief Procedure qui ajoute du score au joueur qui a tué l'autre
     * @param[in,out] players : le vecteur des joueurs
     * @fn scorePlayer(player::Player &player)
     */
    void scorePlayer(player::Player &player);
    /**
     * @brief Renvoie l'affichage du score actuel avec les pseudos des joueurs
     * @param[in] players : Le vecteurs des joueurs
     * @return nsGui::Text : Le score des joueurs
     * @fn showScore(std::vector<player::Player> &players, MinGL &window)
     */
    nsGui::Text showScore(std::vector<player::Player> &players, MinGL &window);
    /**
     * @brief Lit le fichier des meilleurs scores et en fait un vecteur
     * @param[in] path : le chemin du fichier scoreBoard
     * @return std::vector<std::string> : le vecteur du score
     * @fn highScoreReader(std::string & path)
     */
    std::vector<std::string> highScoreReader(std::string & path);
    /**
     * @brief Interprete le vecteur renvoyé par highScoreReader, y ajoute les score actuel, si néscessaire
     * @param[in] players : le vecteur de joueurs
     * @return std::vector<std::string> : le vecteur du score mais correctement trié
     * @fn highScoreUpdate(std::vector<player::Player> &players)
     */
    std::vector<std::string> highScoreUpdate(std::vector<player::Player> &players);
    /**
     * @brief Procedure qui écris le score dans le fichier des scores
     * @param [in]players : le vecteurs des joueurs
     * @fn highScoreWriter(std::vector<player::Player> &players)
     */
    void highScoreWriter(std::vector<player::Player> &players);
}

#endif //S102_SCORE_H