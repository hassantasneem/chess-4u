#pragma once

#include "Board.h"

#include <string>

class Game {
private:
    Board board;
    char currentTurn;
    bool gameOver;

    void showMenu() const;
    void switchTurn();
    bool parsePosition(const std::string& position, int& row, int& col) const;
    std::string playerName(char color) const;

public:
    Game();
    void start();
};
