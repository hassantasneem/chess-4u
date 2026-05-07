#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
    Queen(char pieceColor);
    bool isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const override;
};
