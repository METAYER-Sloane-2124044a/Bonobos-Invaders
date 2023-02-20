/**
 * @file    player.h
 * @author  Alexis MARIOTTI | Marius PISTORESI
 * @date    Décembre 2021
 * @version 1.0
 * @brief   Permet de gérer les joueurs
 **/

#include "game/entities/torpedo.h"
#include "game/yaml/configReader.h"
#include "game/graphic/bonobo.h"
#include "game/graphic/life.h"

#ifndef S102_PLAYER_H
#define S102_PLAYER_H

namespace player {

    /**
     * @brief Configuration dans l'espace vide de la configuration
     * @param[in] configMap : map de la configuration
     * @fn init(std::map<std::string,std::string> &configMap)
     */
    void init(std::map<std::string,std::string> &configMap);

    /**
     * @brief Structure de joueur pour pouvoir les traiter en instance
     */
    struct Player {

        //Variable du joueur
        nsGraphics::Vec2D pos;
        std::vector<unsigned long> size;
        int life;
        unsigned shootLimit;
        unsigned shootCount;
        unsigned id;
        unsigned score;
        std::string pseudo;

        /**
         * @brief Fonction constructeur de la struct Player
         * @param[in] entX : position X
         * @param[in] entY : position Y
         * @param[in] entId : id du joueur
         * @fn Player(int entX, int entY, unsigned entId)
         */
        Player(int entX, int entY, unsigned entId);

        /**
         * @brief Fonction de mise à jour du joueur en bloquant le tir
         * @fn update()
         */
        void update();

        /**
         * @brief Fonction qui ajoute une torpille allié au vecteur de torpilles et l'initialise
         * @param[in] from : quel joueur tir
         * @param[in] to : vers ou le joueur tir
         * @param[in,out] torpedos : vecteur de torpilles
         * @fn shoot(unsigned from, unsigned to)
         */
         void shoot(unsigned from, unsigned to, std::vector<torpedo::Torpedo> &torpedos);

        /**
         * @brief Permet d'afficher le joueur
         * @param[in,out] window : fenêtre de jeu
         * @fn nsShape::Rectangle show(MinGL &window)
         */
        void show(MinGL &window);

        /**
         * @brief Affiche la vie du joueur
         * @param window : La fenêtre de jeu
         * @param pos : La position de oû sont affiché les vies
         * @fn showLife(MinGL& window, nsGraphics::Vec2D &pos)
         */
        void showLife(MinGL &window, nsGraphics::Vec2D pos);
    };
}
#endif //S102_PLAYER_H
