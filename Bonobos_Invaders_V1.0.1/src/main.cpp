#include <iostream>
#include <thread>
#include <cstdlib>

#include <stdio.h>
#include <string.h>

#include "game/scenes/menu.h"
#include "game/scenes/multi.h"
#include "game/scenes/credits.h"
#include "game/scenes/highScore.h"
#include "game/scenes/winningScreen.h"

#include "mingl/mingl.h"

std::map<std::string, std::string> configMap=reader::configMapReader();
unsigned fps (std::stoul(configMap["fpsLimit"]));
#define FPS_LIMIT fps

using namespace std;
using namespace menu;

/**
 * @brief Cette fonction a été récupéré sur le site https://stackoverflow.com/questions/16455024/how-can-i-get-screen-resolution-in-c-operating-system-qnx-or-linux/16457921. Elle sert à récupérer la taille de l'écran.
 * @return static unsigned short size[2] : la taille de l'écran
 * @fn *get_screen_size()
 */
unsigned short *get_screen_size(){
    static unsigned short size[2];
    char *array[8];
    char screen_size[64];
    char* token = NULL;

    FILE *cmd = popen("xdpyinfo | awk '/dimensions/ {print $2}'", "r");

    if (!cmd)
        return 0;

    while (fgets(screen_size, sizeof(screen_size), cmd) != NULL);
    pclose(cmd);

    token = strtok(screen_size, "x\n");

    if (!token)
        return 0;

    for (unsigned short i = 0; token != NULL; ++i) {
        array[i] = token;
        token = strtok(NULL, "x\n");
    }
    size[0] = atoi(array[0]);
    size[1] = atoi(array[1]);
    size[2] = -1;

    return size;
}

/**
 * @brief Affiche le texte de chargement
 * @param[in] percent : pourcentage de progression
 * @param[in] text : texte à afficher
 * @param[in,out] window : fenêtre de jeu
 */
void loading(unsigned percent, string text, MinGL &window){
    window.clearScreen();
    string content = "Chargement : " + text + " | " + to_string(percent) + "%";
    window << nsGui::Text(nsGraphics::Vec2D(0,13),content,nsGraphics::KWhite);
    window << nsGui::Text(nsGraphics::Vec2D(0,39),"Pensez a quitter le jeu avec la touche retour present dans le menu sinon il risque d'y avoir des problemes de son ;-)",nsGraphics::KWhite);
    window.finishFrame();
}

int main()
{
    //Récupération de la fenêtre
    unsigned short *screenSize = get_screen_size();

    // Initialise le système
    MinGL window("Bonobo-Invaders", nsGraphics::Vec2D(1358, 760), nsGraphics::Vec2D(screenSize[0]/2-679, screenSize[1]/2-380), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    //Initialise les sprites
    string imgPath = configMap["imgPath"]+"/";
    loading(0,"sprite : menu.si2",window);
    nsGui::Sprite menu (imgPath+"menu.si2");
    loading(13,"sprite : victoryl.si2",window);
    nsGui::Sprite victoryl (imgPath+"victory_l.si2");
    loading(26,"sprite : victoryr.si2",window);
    nsGui::Sprite victoryr (imgPath+"victory_r.si2");
    loading(39,"sprite : credits.si2",window);
    nsGui::Sprite credits (imgPath+"credits.si2");
    loading(52,"sprite : selectName.si2",window);
    nsGui::Sprite selectName (imgPath+"select_name.si2");
    loading(65,"sprite : selectName.si2",window);
    nsGui::Sprite highScore (imgPath+"highscore.si2");
    loading(78,"sprite : back_game.si2",window);
    nsGui::Sprite gameBackGround (imgPath+"back_game.si2");

    //Initialisation avec le fichier config
    unsigned currentScene (0); //Met la scène au menu soit 0
    loading(91,"config",window);
    menu::init(configMap,menu);
    loading(92,"config",window);
    multi::initConfig(configMap);
    loading(93,"config",window);
    multi::init(window);
    loading(95,"config",window);
    highScore::init(configMap);
    loading(96,"config",window);
    enemy::init(configMap);
    loading(97,"config",window);
    player::init(configMap);
    loading(98,"config",window);
    torpedo::init(configMap);
    loading(99,"config",window);
    score::init(configMap);
    loading(100,"config",window);
    winningScreen::init(configMap);
    waveManager::initEnemies(configMap);

    //Initialise la musique
    system("cvlc --loop ../files/bonobo_loop.mp3 &");

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();
    unsigned winninningScreenCountForFrame=0;

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen())
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        //Rendu de la scène en cours
        switch (currentScene) {
            case 0:
                menu::render(window);
                currentScene = menu::update(window);
                break;
            case 1:
                multi::render(window,gameBackGround);
                currentScene = multi::update(window);
                break;
            case 2:
                currentScene = highScore::update(window);
                highScore::render(window, highScore);
                winninningScreenCountForFrame=0;
                break;
            case 3:
                currentScene = credits::update(window);
                credits::render(window, credits);
                break;
            case 4:
                getPseudo::render(window, selectName);
                currentScene=getPseudo::update(window);
                break;
            case 5:
                winningScreen::renderLeft(window,victoryl);
                currentScene=winningScreen::updateLeft(window,winninningScreenCountForFrame);
                ++winninningScreenCountForFrame;
                break;
            case 6:
                winningScreen::renderRight(window,victoryr);
                currentScene=winningScreen::updateRigth(window,winninningScreenCountForFrame);
                ++winninningScreenCountForFrame;
        }

        // On finit la frame en cours
        window.finishFrame();

        // On vide la queue d'évènements
        window.getEventManager().clearEvents();

        // On attend un peu pour limiter le framerate et soulager le CPU
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // On récupère le temps de frame
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }
    return 0;
}
