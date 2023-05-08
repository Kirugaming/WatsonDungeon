//
// Created by kirut on 4/28/2023.
//

#ifndef WATSONDUNGEON_GAME_H
#define WATSONDUNGEON_GAME_H

#include <iostream>
#include <fstream>
#include <vector>

struct Player {
    int x;
    int y;
    int health;
    int maxHealth;

    Player() : x(0), y(0), health(100), maxHealth(100) {}
};

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    Player player;
    std::vector<std::vector<char>> level;

    void processInput();
};


#endif //WATSONDUNGEON_GAME_H
