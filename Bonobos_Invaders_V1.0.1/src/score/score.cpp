//
// Created by alexis on 21/12/2021.
//
#include "game/score/score.h"

unsigned multiplier;
std::string scoreBoardPath;

void score::init(std::map<std::string,std::string> &configMap){
    multiplier=stoul(configMap["scoreMultiplier"]);
    scoreBoardPath=configMap["scorePath"];
}

void score::scoreInvader(unsigned from,enemy::Enemy &enemy, std::vector<player::Player> &players){
    player::Player &shooter = players[from-1];
    //calcule le score par rapport à la distanc entre le joueur et l'enemie
    unsigned range = std::abs(shooter.pos.getX()-enemy.pos.getX());
    //ajoute ce score au score du joueur
    shooter.score += range*multiplier;
}


void score::scorePlayer(player::Player &player){
    player.score += 1000*multiplier;
}

nsGui::Text score::showScore(std::vector<player::Player> &players, MinGL &window){
    std::string text=players[0].pseudo+" "+std::to_string(players[0].score)+" - "+std::to_string(players[1].score)+" "+players[1].pseudo;
    nsGraphics::Vec2D position=nsGraphics::Vec2D(window.getWindowSize().getX()/2-((std::to_string(players[0].score).size()+6)*9),window.getWindowSize().getY()/12);
    return nsGui::Text(position, text, nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
}

std::vector<std::string> score::highScoreReader(std::string & path){
    std::ifstream ifs;
    std::vector<std::string> scoreBoard;
    ifs.open (path, std::ios_base::in);
    //replie le vecteur avec les lignes du fichier
    while (true)
    {
        std::string str;
        getline(ifs,str);
        if (str=="") break;
        scoreBoard.push_back(str);
        if (ifs.eof ()) break;
    }
    return scoreBoard;
}

std::vector<std::string> score::highScoreUpdate(std::vector<player::Player> &players){
    std::vector<std::string> scoreBoard(highScoreReader(scoreBoardPath));
    std::vector<std::string> pseudos;
    std::vector<unsigned> scores;
    for (std::string line:scoreBoard) {    //on sépare dans 2 vecteur pour pouvoir traité les données
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
        scores.push_back(stoul(score));
        pseudos.push_back(pseudo);
    }
    //on ajoute les nouveau score
    scores.push_back(players[0].score);
    scores.push_back(players[1].score);
    pseudos.push_back(players[0].pseudo);
    pseudos.push_back(players[1].pseudo);
    //on trie dans l'ordre décroissant
    for (unsigned i = 0; i < scores.size()-1; ++i) {
        unsigned max = i;
        for (unsigned j = i + 1; j < scores.size(); ++j) {
            if (scores[j] > scores[max]) {
                max = j;
            }
        }
        if (max != i) {
            std::swap(scores[i], scores[max]);
            std::swap(pseudos[i], pseudos[max]); //on trie pseudos selon le trie de scores pour garder les meme indices
        }
    }
    scoreBoard.resize(0);
    //on réunifie les 2 vecteurs en 1 seul et on ne garde que les 10 meilleur scores
    for (unsigned i = 0; i <scores.size() && i<10; ++i) {
        scoreBoard.push_back(pseudos[i] + " " + std::to_string(scores[i]));
    }
    return scoreBoard;
}

void score::highScoreWriter(std::vector<player::Player> &players){
    std::ofstream ofs;
    char test;
    std::vector<std::string> scoreBoard(highScoreUpdate(players));
    ofs.open(scoreBoardPath, std::ios_base::out);
    for (std::string line: scoreBoard)
        ofs<<line<<std::endl;
    ofs.close();
}