//
// Created by marius on 13/12/2021.
//


#include "game/scenes/menu.h"

int valSelection (0);

nsGui::Sprite backgroundSprite ("../files/img/empty.si2",nsGraphics::Vec2D(0,0));

void menu::init(std::map<std::string,std::string> &configMap, nsGui::Sprite &background){
    std::ifstream ifs;
    ifs.open ( configMap["creditsPath"], std::ios_base::in);
    backgroundSprite = background;
}

unsigned menu::update(MinGL &window) {
    //Si la touche gauche est appuyé, si on est pas tout à gauche, déplacement vers la gauche
    if (window.isPressed({GLUT_KEY_LEFT, true}) && valSelection > 0) {
        --valSelection;
        window.resetKey({GLUT_KEY_LEFT, true});
    }
    //sinon si la touche droite est appuyé, si on est pas tout à droite, déplacement vers la droite
    else if (window.isPressed({GLUT_KEY_RIGHT, true}) && valSelection < 3) {
        ++valSelection;
        window.resetKey({GLUT_KEY_RIGHT, true});
    }
    //Si la touche entrée est pressé, action suivant la boutton selectioné
    if (window.isPressed({13, false})){
        window.resetKey({13, false});
        switch (valSelection) {
            case 0:
                return 4;
            case 1:
                return 2;
            case 2:
                return 3;
            case 3:
                //Permet de kill le processus
                system("pkill -f vlc");
                window.stopGraphic();
                break;
        }
    }
    return 0;
}

void menu::showMultiButton(MinGL &window) {
    //Si le bouton est selectionné, l'affiche en tant que tel
    nsGraphics::Vec2D pos (379,550);
    if (valSelection == 0) play_button::draw(window,pos,200,'n');
    else play_button::draw(window,pos,200,'y');
}

void menu::showHighScore(MinGL &window){
    //Si le bouton est selectionné, l'affiche en tant que tel
    nsGraphics::Vec2D pos (619,550);
    if (valSelection == 1) highscore_button::draw(window,pos,200,'n');
    else highscore_button::draw(window,pos,200,'y');
}

void menu::showCreditButton(MinGL &window) {
    //Si le bouton est selectionné, l'affiche en tant que tel
    nsGraphics::Vec2D pos (859,550);
    if (valSelection == 2) credit_button::draw(window,pos,200,'n');
    else credit_button::draw(window,pos,200,'y');
}

void menu::showExitButton(MinGL &window) {
    //Si le bouton est selectionné, l'affiche en tant que tel
    nsGraphics::Vec2D pos (989,550);
    if (valSelection == 3) exit_button::draw(window,pos,80,'n');
    else exit_button::draw(window,pos,80,'y');
}

nsGui::Text menu::showVersion(MinGL &window){
    std::string version = "Realese Bonobos Invaders V1.0.1";
    return nsGui::Text(nsGraphics::Vec2D(window.getWindowSize().getX()-(version.size()*10), window.getWindowSize().getY()-18), version, nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
}

void menu::render(MinGL &window) {
    window << backgroundSprite  << showVersion(window);
    showMultiButton(window);
    showHighScore(window);
    showCreditButton(window);
    showExitButton(window);
}