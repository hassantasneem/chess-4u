#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
    Knight(char pieceColor);
    bool isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const override;
};
