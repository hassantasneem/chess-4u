#include "Board.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

#include <iostream>

using namespace std;

Board::Board() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            squares[row][col] = nullptr;
        }
    }

    setupBoard();
}

Board::~Board() {
    clearBoard();
}

void Board::clearBoard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            delete squares[row][col];
            squares[row][col] = nullptr;
        }
    }
}

void Board::placeMajorPieces(char color, int row) {
    squares[row][0] = new Rook(color);
    squares[row][1] = new Knight(color);
    squares[row][2] = new Bishop(color);
    squares[row][3] = new Queen(color);
    squares[row][4] = new King(color);
    squares[row][5] = new Bishop(color);
    squares[row][6] = new Knight(color);
    squares[row][7] = new Rook(color);
}

void Board::setupBoard() {
    clearBoard();

    placeMajorPieces('b', 0);
    for (int col = 0; col < 8; col++) {
        squares[1][col] = new Pawn('b');
    }

    for (int col = 0; col < 8; col++) {
        squares[6][col] = new Pawn('w');
    }
    placeMajorPieces('w', 7);
}

void Board::display() const {
    cout << "\n    a   b   c   d   e   f   g   h\n";
    cout << "  +---+---+---+---+---+---+---+---+\n";

    for (int row = 0; row < 8; row++) {
        cout << 8 - row << " |";

        for (int col = 0; col < 8; col++) {
            if (squares[row][col] == nullptr) {
                cout << "   |";
            } else {
                cout << squares[row][col]->getDisplayName() << " |";
            }
        }

        cout << " " << 8 - row << "\n";
        cout << "  +---+---+---+---+---+---+---+---+\n";
    }

    cout << "    a   b   c   d   e   f   g   h\n\n";
}

Piece* Board::getPiece(int row, int col) const {
    if (!isInsideBoard(row, col)) {
        return nullptr;
    }

    return squares[row][col];
}

bool Board::isInsideBoard(int row, int col) const {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

bool Board::isSquareEmpty(int row, int col) const {
    return isInsideBoard(row, col) && squares[row][col] == nullptr;
}

bool Board::isPathClear(int startRow, int startCol, int endRow, int endCol) const {
    int rowDirection = 0;
    int colDirection = 0;

    if (endRow > startRow) {
        rowDirection = 1;
    } else if (endRow < startRow) {
        rowDirection = -1;
    }

    if (endCol > startCol) {
        colDirection = 1;
    } else if (endCol < startCol) {
        colDirection = -1;
    }

    int row = startRow + rowDirection;
    int col = startCol + colDirection;

    while (row != endRow || col != endCol) {
        if (squares[row][col] != nullptr) {
            return false;
        }

        row += rowDirection;
        col += colDirection;
    }

    return true;
}

bool Board::movePiece(int startRow, int startCol, int endRow, int endCol, char currentTurn, bool& kingCaptured) {
    kingCaptured = false;

    if (!isInsideBoard(startRow, startCol) || !isInsideBoard(endRow, endCol)) {
        cout << "Invalid board position.\n";
        return false;
    }

    if (startRow == endRow && startCol == endCol) {
        cout << "Source and destination cannot be the same.\n";
        return false;
    }

    Piece* selectedPiece = squares[startRow][startCol];
    Piece* destinationPiece = squares[endRow][endCol];

    if (selectedPiece == nullptr) {
        cout << "No piece found at the selected position.\n";
        return false;
    }

    if (selectedPiece->getColor() != currentTurn) {
        cout << "You can only move your own pieces.\n";
        return false;
    }

    if (destinationPiece != nullptr && destinationPiece->getColor() == currentTurn) {
        cout << "You cannot capture your own piece.\n";
        return false;
    }

    if (!selectedPiece->isValidMove(startRow, startCol, endRow, endCol, this)) {
        cout << "Invalid move for this piece.\n";
        return false;
    }

    if (destinationPiece != nullptr && destinationPiece->getSymbol() == 'K') {
        kingCaptured = true;
    }

    delete destinationPiece;
    squares[endRow][endCol] = selectedPiece;
    squares[startRow][startCol] = nullptr;

    return true;
}
