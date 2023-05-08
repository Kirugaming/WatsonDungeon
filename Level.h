//
// Created by kirut on 5/8/2023.
//

#ifndef WATSONDUNGEON_LEVEL_H
#define WATSONDUNGEON_LEVEL_H


#include <utility>
#include <vector>

class Level {
public:
    std::vector<std::vector<char>> level;
    int coins;
    std::pair<int, int> initPlayerPos;

    Level();
    Level(std::vector<std::vector<char>> level, int coins) : level(std::move(level)), coins(coins) {};
};


#endif //WATSONDUNGEON_LEVEL_H
