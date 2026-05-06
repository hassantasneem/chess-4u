#pragma once

#include <string>

class Board;

class Piece {
protected:
    char color;
    char symbol;

public:
    Piece(char pieceColor, char pieceSymbol);
    virtual ~Piece();

    char getColor() const;
    char getSymbol() const;
    std::string getDisplayName() const;

    virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const = 0;
};
