//
// Created by kirut on 4/28/2023.
//

#ifndef WATSONDUNGEON_GAME_H
#define WATSONDUNGEON_GAME_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Player.h"
#include "Level.h"


class Game {
public:
    Game();
    ~Game();
    void run();

private:
    Player player;
    std::vector<Level*> levels;
    Level *currentLevel;

    void colorText(char tile);
    void processInput();
    void checkPlayerPos();
};


#endif //WATSONDUNGEON_GAME_H
