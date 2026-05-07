#include "Bishop.h"
#include "Board.h"

#include <cstdlib>

Bishop::Bishop(char pieceColor) : Piece(pieceColor, 'B') {}

bool Bishop::isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const {
    bool diagonalMove = std::abs(endRow - startRow) == std::abs(endCol - startCol);
    return diagonalMove && board->isPathClear(startRow, startCol, endRow, endCol);
}
