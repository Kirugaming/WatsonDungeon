//
// Created by kirut on 5/8/2023.
//

#ifndef WATSONDUNGEON_PLAYER_H
#define WATSONDUNGEON_PLAYER_H


struct Player {
    int x;
    int y;
    int health;
    int maxHealth;
    int obtainedCoins = 0;

    Player() : x(0), y(0), health(100), maxHealth(100) {}
    Player(int x, int y) : x(x), y(y), health(100), maxHealth(100) {}
};



#endif //WATSONDUNGEON_PLAYER_H
