#include "Queen.h"
#include "Board.h"

#include <cstdlib>

Queen::Queen(char pieceColor) : Piece(pieceColor, 'Q') {}

bool Queen::isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const {
    bool straightMove = startRow == endRow || startCol == endCol;
    bool diagonalMove = std::abs(endRow - startRow) == std::abs(endCol - startCol);
    return (straightMove || diagonalMove) && board->isPathClear(startRow, startCol, endRow, endCol);
}
