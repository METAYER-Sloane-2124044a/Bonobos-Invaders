//
// Created by marius on 16/12/2021.
//

#include "game/scenes/highScore.h"

std::vector<std::string> scoreBoardPseudos, scoreBoardScores;

void highScore::init(std::map<std::string,std::string> &configMap){
    //Netoyage des variables pour éviter trop d'informations
    scoreBoardScores.clear();
    scoreBoardPseudos.clear();
    //Lecture du fichier de config pour avoir le chemin
    std::vector<std::string> scoreBoardToCut=score::highScoreReader(configMap["scorePath"]);
    for (std::string line:scoreBoardToCut) {    //on sépare dans 2 vecteur pour pouvoir traité les données
        std::string pseudo;
        std::string score;
        for (int i = 0; i < line.size(); ++i) {
            if (i < 4)
                pseudo += line[i];
            else if (i == 4)
                continue;
            else
                score += line[i];
        }
        scoreBoardScores.push_back(score);
        scoreBoardPseudos.push_back(pseudo);
    }
}

unsigned int highScore::update(MinGL &window) {
    if (window.isPressed({13, false})){
        window.resetKey({13, false});
        return 0;
    }
    return 2;
}

void highScore::render(MinGL &window, nsGui::Sprite &background) {
    window << background;
    for (int i = 0; i < scoreBoardPseudos.size(); ++i) {
        window << nsGui::Text(nsGraphics::Vec2D(525, 340+i*23.3), scoreBoardPseudos[i], nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
    }
    for (int i = 0; i < scoreBoardScores.size(); ++i) {
        window << nsGui::Text(nsGraphics::Vec2D(690, 340+i*23.5), scoreBoardScores[i], nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
    }
}