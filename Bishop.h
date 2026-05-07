#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(char pieceColor);
    bool isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const override;
};
