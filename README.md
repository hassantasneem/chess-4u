# ♟️ Chess 4u - Console Based Chess Game
**OOP Semester Project | Spring 2026** **National University of Computer and Emerging Sciences (FAST-NUCES)**

A fully functional, object-oriented console-based Chess game implemented in C++. This project was developed to demonstrate the practical application of core Object-Oriented Programming principles including Inheritance, Polymorphism, and Encapsulation.

---

## Authors
* **Muhammad Hassan Tasneem** - [GitHub Profile](https://github.com/hassantasneem)
* **Mahad Itqaan Naser** - [GitHub Profile](https://github.com/mahaddnasir)

---

## Features
* **Full Move Validation:** Each piece (Pawn, Rook, Knight, Bishop, Queen, King) follows its standard movement rules.
* **Path Checking:** Detects if a piece is blocked by other pieces (for sliding pieces like Rook and Bishop).
* **Turn Management:** Alternating gameplay between White and Black players.
* **Capture Detection:** Proper handling of piece captures and King protection.
* **User Interface:** Clean console display with algebraic notation input support (e.g., `e2 e4`).

---

## Technical Implementation
This project utilizes the following OOP concepts:
* **Inheritance:** A base `Piece` class with derived classes for each specific piece type.
* **Polymorphism:** Utilizing `virtual` functions for `isValidMove()` to ensure dynamic binding at runtime.
* **Abstraction:** Using pure virtual functions to define a template for all chess pieces.
* **Composition:** The `Board` class manages a collection of `Piece` pointers.

---

## Project Structure
```text
├── main.cpp          # Game entry point
├── Game.h/.cpp       # Game loop and turn logic
├── Board.h/.cpp      # 8x8 Grid management and move validation
├── Piece.h/.cpp      # Base class for all pieces
└── Pieces/           # Derived classes (Pawn, Knight, etc.)
