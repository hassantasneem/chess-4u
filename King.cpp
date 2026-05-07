#include "King.h"

#include <cstdlib>

King::King(char pieceColor) : Piece(pieceColor, 'K') {}

bool King::isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const {
    (void)board;
    int rowChange = std::abs(endRow - startRow);
    int colChange = std::abs(endCol - startCol);
    return rowChange <= 1 && colChange <= 1;
}
