//
// Created by kirut on 5/8/2023.
//

#include <fstream>
#include "Level.h"

Level::Level() {

    std::ifstream levelFile("Assets/Levels/level.dat");

    if (levelFile.is_open()) {
        level = std::vector<std::vector<char>>();
        std::string line;
        while (std::getline(levelFile, line)) {
            std::vector<char> row;
            for (char c : line) {
                row.push_back(c);
            }
            level.push_back(row);
        }

        levelFile.close();
    }

    // find player and coins in level
    coins = 0;
    for (int i = 0; i < level.size(); ++i) {
        for (int j = 0; j < level.at(i).size(); ++j) {
            if (level.at(i).at(j) == '@') { // player
                initPlayerPos = std::make_pair(j, i);
            } else if (level.at(i).at(j) == '*') { // coin
                coins++;
            }
        }
    }
};
