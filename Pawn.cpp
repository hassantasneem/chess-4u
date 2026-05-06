#include "Pawn.h"
#include "Board.h"

#include <cstdlib>

Pawn::Pawn(char pieceColor) : Piece(pieceColor, 'P') {}

bool Pawn::isValidMove(int startRow, int startCol, int endRow, int endCol, Board* board) const {
    int direction = (color == 'w') ? -1 : 1;
    int startRank = (color == 'w') ? 6 : 1;
    int rowChange = endRow - startRow;
    int colChange = std::abs(endCol - startCol);
    Piece* destination = board->getPiece(endRow, endCol);

    if (startCol == endCol && destination == nullptr) {
        if (rowChange == direction) {
            return true;
        }

        if (startRow == startRank && rowChange == 2 * direction) {
            int middleRow = startRow + direction;
            return board->isSquareEmpty(middleRow, startCol);
        }
    }

    if (colChange == 1 && rowChange == direction && destination != nullptr && destination->getColor() != color) {
        return true;
    }

    return false;
}
