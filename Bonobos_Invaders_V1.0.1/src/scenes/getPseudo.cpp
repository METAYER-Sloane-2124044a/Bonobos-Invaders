//
// Created by alexis on 26/12/2021.
//
#include "game/scenes/getPseudo.h"

std::string alpha="abcdefghijklmnopqrstuvwxyz";
std::vector<std::string> pseudos(2);
unsigned actual=0;

void getPseudo::init(unsigned number) {
    pseudos.resize(0);
    actual=0;
    pseudos.resize(number);
}

unsigned getPseudo::update(MinGL &window){
    //verifie si une lettre de l'alphabet est appuyé, si oui, l'ajoute au pseudo en cours de rédaction
    for (const char &key: alpha) {
        if (window.isPressed({key, false}) && pseudos[actual].size() < 4) {
            window.resetKey({key, false});
            pseudos[actual] += key;
        }
    }
    //Verifie si la touche retour ou supr est pressé, on efface une lettre du pseudo en cours de rédaction
    if ((window.isPressed({8, false}) or window.isPressed({127, false})) && pseudos[actual].size() > 0) {
        window.resetKey({8, false});
        window.resetKey({127, false});
        std::string oldPseudo = pseudos[actual];
        pseudos[actual] = "";
        for (std::string::iterator i=oldPseudo.begin(); i != oldPseudo.end()-1; ++i)
            pseudos[actual] += *i;
    }
    //Verifie si la touche entré est prssé, uniquement lorsque la taille du pseudo en cours de rédaction est bonne, si la touche est préssé le pseudo en cours de rédaction est validé
    if (pseudos[actual].size() == 4 && window.isPressed({13, false})) {
        window.resetKey({13, false});
        ++actual;
        if (pseudos.size() == actual) {
            return 1;
        }
    }
    return 4;
}

void getPseudo::render(MinGL &window, nsGui::Sprite &background){
    window << background;
    //affiche le pseudo en cours de rédaction
    window<<nsGui::Text(nsGraphics::Vec2D(655,387), pseudos[actual], nsGraphics::KBlack, nsGui::GlutFont::BITMAP_HELVETICA_18);
}

std::vector<std::string> getPseudo::getPseudo() {
    return pseudos;
}
