#include "Piece.h"

Piece::Piece(char pieceColor, char pieceSymbol) {
    color = pieceColor;
    symbol = pieceSymbol;
}

Piece::~Piece() {}

char Piece::getColor() const {
    return color;
}

char Piece::getSymbol() const {
    return symbol;
}

std::string Piece::getDisplayName() const {
    std::string name;
    name += color;
    name += symbol;
    return name;
}
