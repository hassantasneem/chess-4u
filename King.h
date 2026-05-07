#pragma once
#include "Piece.h"

class King : public Piece {
public:
    King(char pieceColor);
    bool isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const override;
};
