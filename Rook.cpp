#include "Rook.h"
#include "Board.h"

Rook::Rook(char pieceColor) : Piece(pieceColor, 'R') {}

bool Rook::isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const {
    bool straightMove = startRow == endRow || startCol == endCol;
    return straightMove && board->isPathClear(startRow, startCol, endRow, endCol);
}
