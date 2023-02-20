//
// Created by alexis on 16/12/2021.
//

#include "game/scenes/credits.h"


using namespace credits;

unsigned credits::update(MinGL &window){
    if (window.isPressed({13, false})){
        window.resetKey({13, false});
        return 0;
    }
    return 3;
}

void credits::render(MinGL &window, nsGui::Sprite &background){
    window<<background;
}
