#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
    Rook(char pieceColor);
    bool isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const override;
};
