#include "Game.h"
#include <cctype>
#include <iostream>
#include <limits>

using namespace std;

Game::Game() {
    currentTurn = 'w';
    gameOver = false;
}

void Game::showMenu() const {
    cout << "====================================\n";
    cout << "        TWO PLAYER CHESS GAME\n";
    cout << "====================================\n";
    cout << "1. Start Game\n";
    cout << "2. Exit\n";
    cout << "Enter choice: ";
}

void Game::switchTurn() {
    currentTurn = (currentTurn == 'w') ? 'b' : 'w';
}

bool Game::parsePosition(const string& position, int& row, int& col) const {
    if (position.length() != 2) {
        return false;
    }

    char file = static_cast<char>(tolower(position[0]));
    char rank = position[1];

    if (file < 'a' || file > 'h' || rank < '1' || rank > '8') {
        return false;
    }

    col = file - 'a';
    row = 8 - (rank - '0');

    return true;
}

string Game::playerName(char color) const {
    return (color == 'w') ? "White" : "Black";
}

void Game::start() {
    int choice;

    showMenu();
    cin >> choice;

    if (cin.fail() || choice != 1) {
        cout << "Exiting game.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (!gameOver) {
        string source;
        string destination;
        int startRow;
        int startCol;
        int endRow;
        int endCol;
        bool kingCaptured = false;

        board.display();

        cout << playerName(currentTurn) << "'s turn\n";
        cout << "Enter piece position (example e2), or q to quit: ";
        cin >> source;

        if (source == "q" || source == "Q") {
            cout << "Game ended by player.\n";
            return;
        }

        cout << "Enter move position (example e4): ";
        cin >> destination;

        if (!parsePosition(source, startRow, startCol) || !parsePosition(destination, endRow, endCol)) {
            cout << "Invalid input format. Use positions like e2 and e4.\n";
            continue;
        }

        if (board.movePiece(startRow, startCol, endRow, endCol, currentTurn, kingCaptured)) {
            cout << "Move successful.\n";

            if (kingCaptured) {
                board.display();
                cout << playerName(currentTurn) << " wins! King captured.\n";
                gameOver = true;
            } else {
                switchTurn();
            }
        }
    }
}
