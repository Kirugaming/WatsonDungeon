//
// Created by kirut on 4/28/2023.
//

#include <conio.h>
#include "Game.h"

Game::Game() : player() {
    std::ifstream levelFile("level.dat");

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

    // find @ in map
    for (int i = 0; i < level.size(); i++) {
        for (int j = 0; j < level[i].size(); j++) {
            if (level[i][j] == '@') {
                player.x = j;
                player.y = i;
            }
        }
    }


}

Game::~Game() = default;

void Game::run() {
// print the level
    while (true) {
        system("cls");
        for (int i = 0; i < level.size(); ++i) {
            for (int j = 0; j < level.at(i).size(); ++j) {
                if (i == player.y && j == player.x) {
                    std::cout << '@';
                } else {
                    std::cout << level.at(i).at(j);
                }
            }
            std::cout << std::endl;
        }
        processInput();
    }

}

void Game::processInput() {
    char input = _getch();

    switch (input) {
        case 'w':
            level.at(player.y).at(player.x) = '.';
            player.y--;
            break;
        case 'a':
            level.at(player.y).at(player.x) = '.';
            player.x--;
            break;
        case 's':
            level.at(player.y).at(player.x) = '.';
            player.y++;
            break;
        case 'd':
            level.at(player.y).at(player.x) = '.';
            player.x++;
            break;
        default:
            break;
    }
}
