//
// Created by kirut on 4/28/2023.
//

#include <conio.h>
#include "Game.h"

Game::Game() {
    levels = std::vector<Level *>();
    currentLevel = new Level();
    levels.push_back(currentLevel);

    player = Player(currentLevel->initPlayerPos.first, currentLevel->initPlayerPos.second);

}

Game::~Game() = default;

void Game::run() {
    // title screen
    std::ifstream title("Assets/title.txt");
    std::string titleString;
    while (std::getline(title, titleString)) {
        std::cout << titleString << std::endl;
    }
    while (std::cin.get() != '\n') {
        std::cout << "Press enter to continue..." << std::endl;
    }
    title.close();

    // print the level
    while (true) {
        system("cls");
        for (int i = 0; i < currentLevel->level.size(); ++i) {
            for (int j = 0; j < currentLevel->level.at(i).size(); ++j) {
                if (player.x == j && player.y == i) {
                    std::cout << '@';
                } else {
                    std::cout << currentLevel->level.at(i).at(j);
                }
            }

            // print coins
            if (i == 2) {
                std::cout << "\tWatson Coins: " << player.obtainedCoins << "/" << currentLevel->coins;
            }

            std::cout << std::endl;
        }
        std::cout << "WASD to move" << std::endl;
        processInput();
    }

}

void Game::processInput() {
    char input = _getch();

    switch (input) {
        case 'w':
            currentLevel->level.at(player.y).at(player.x) = '-';
            player.y--;

            // check for wall #
            if (currentLevel->level.at(player.y).at(player.x) == '#') {
                player.y++;
            }

            checkPlayerPos();
            break;
        case 'a':
            currentLevel->level.at(player.y).at(player.x) = '-';
            player.x--;

            // check for wall #
            if (currentLevel->level.at(player.y).at(player.x) == '#') {
                player.x++;
            }

            checkPlayerPos();
            break;
        case 's':
            currentLevel->level.at(player.y).at(player.x) = '-';
            player.y++;

            // check for wall #
            if (currentLevel->level.at(player.y).at(player.x) == '#') {
                player.y--;
            }

            checkPlayerPos();
            break;
        case 'd':
            currentLevel->level.at(player.y).at(player.x) = '-';
            player.x++;

            // check for wall #
            if (currentLevel->level.at(player.y).at(player.x) == '#') {
                player.x--;
            }

            checkPlayerPos();
            break;
        default:
            break;
    }
}

void Game::checkPlayerPos() {

    if (currentLevel->level.at(player.y).at(player.x) == '*') {
        player.obtainedCoins++;
        currentLevel->level.at(player.y).at(player.x) = '-';
    }
}
