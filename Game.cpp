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
    // play music
    mciSendString("open \"Assets/Audio/title.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);
    std::ifstream title("Assets/title.txt");
    std::string titleString;
    while (std::getline(title, titleString)) {
        // for each character in the line color it red and print it
        for (char c : titleString) {
            std::cout << "\033[48;5;232m" << "\033[38;5;196m" << c << "\033[0m";
        }
        std::cout << std::endl;
    }
    std::cout << "\033[48;5;232m" << "\033[32m" << "If ASCII art is not displaying correctly then go fullscreen :)" << "\033[0m" << std::endl;
    std::cout << "\033[48;5;232m" << "\033[32m" << "Press enter to start the game..." << "\033[0m" << std::endl;
    while (std::cin.get() != '\n') {

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
                    colorText(currentLevel->level.at(i).at(j));
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

void Game::colorText(char tile) {
    switch (tile) {
        case '#': // wall
            std::cout << "\033[1;31m" << tile << "\033[0m";
            break;
        case '*': // coin
            std::cout << "\033[1;33m" << tile << "\033[0m";
            break;
        case '@': // player
            std::cout << "\033[1;32m" << tile << "\033[0m";
            break;
        default:
            std::cout << tile;
            break;

    }
}
