#include <iostream>
#include <fcntl.h>
#include <conio.h>
#include <windows.h>
#include "Game.h"

int main() {
    // enable ANSI escape codes for DOS/CMD
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    Game game;
    game.run();
    return 0;
}
