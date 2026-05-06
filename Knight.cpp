#include "Knight.h"

#include <cstdlib>

Knight::Knight(char pieceColor) : Piece(pieceColor, 'N') {}

bool Knight::isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const {
    (void)board;
    int rowChange = std::abs(endRow - startRow);
    int colChange = std::abs(endCol - startCol);
    return (rowChange == 2 && colChange == 1) || (rowChange == 1 && colChange == 2);
}
