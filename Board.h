#pragma once

class Piece;

class Board {
private:
    Piece* squares[8][8];

    void clearBoard();
    void placeMajorPieces(char color, int row);

public:
    Board();
    ~Board();

    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;

    void setupBoard();
    void display() const;

    Piece* getPiece(int row, int col) const;
    bool isInsideBoard(int row, int col) const;
    bool isSquareEmpty(int row, int col) const;
    bool isPathClear(int startRow, int startCol, int endRow, int endCol) const;
    bool movePiece(int startRow, int startCol, int endRow, int endCol, char currentTurn, bool& kingCaptured);
};
