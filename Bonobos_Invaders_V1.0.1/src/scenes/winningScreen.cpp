//
// Created by alexis on 07/01/2022.
//

#include "game/scenes/winningScreen.h"
unsigned waitWinningScreen;


void winningScreen::init(std::map<std::string,std::string> &configMap){
    waitWinningScreen=stoul(configMap["waitWinningScreen"]);
}

unsigned winningScreen::updateLeft(MinGL &window,unsigned &count){
    //Laisse une frame pour afficher la scene à l'écran
    if (count==0) return 5;
    // Récupère l'heure actuelle
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    //attend le temps donné dans le fichier de configuration
    std::this_thread::sleep_for(std::chrono::seconds (waitWinningScreen) - std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start));
    return 2;
}
unsigned winningScreen::updateRigth(MinGL &window,unsigned &count){
    //Laisse une frame pour afficher la scene à l'écran
    if (count==0) return 6;
    // Récupère l'heure actuelle
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    //attend le temps donné dans le fichier de configuration
    std::this_thread::sleep_for(std::chrono::seconds (waitWinningScreen) - std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start));
    return 2;
}

void winningScreen::renderLeft(MinGL &window, nsGui::Sprite &background){
    std::vector<std::string> playersStats=multi::getScore();
    window<<background;
    nsGraphics::Vec2D bonoboPos=nsGraphics::Vec2D(341,336);
    bonobo::draw(window,bonoboPos,50);
    bonoboPos=nsGraphics::Vec2D(1014,424);
    bonobo::draw(window,bonoboPos,40);
    window<<nsGui::Text(nsGraphics::Vec2D(979,368), playersStats[1]+" - "+playersStats[3], nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18)<<nsGui::Text(nsGraphics::Vec2D(301,266), playersStats[0]+" - "+playersStats[2], nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
}

void winningScreen::renderRight(MinGL &window, nsGui::Sprite &background){
    std::vector<std::string> playersStats=multi::getScore();
    window<<background;
    nsGraphics::Vec2D bonoboPos=nsGraphics::Vec2D(311,424);
    bonobo::draw(window,bonoboPos,40);
    bonoboPos=nsGraphics::Vec2D(1024,336);
    bonobo::draw(window,bonoboPos,50);
    window<<nsGui::Text(nsGraphics::Vec2D(276, 368), playersStats[0]+" - "+playersStats[2], nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18)<<nsGui::Text(nsGraphics::Vec2D(999,266), playersStats[1]+" - "+playersStats[3], nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
}
