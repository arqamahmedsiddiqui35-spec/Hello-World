#include "Board.h"
#include <iostream>

Board::Board() {
    reset();
}

void Board::display() const {
    std::cout << "\n";
    std::cout << "  TIC-TAC-TOE\n";
    std::cout << " ─────────────\n";
    
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) std::cout << "  ";
        
        // Display cell content or position number
        if (cells[i] == ' ') {
            std::cout << " " << (i + 1) << " ";
        } else {
            std::cout << " " << cells[i] << " ";
        }
        
        if (i % 3 != 2) {
            std::cout << "│";
        } else {
            std::cout << "\n";
            if (i < 6) {
                std::cout << "  ───┼───┼───\n";
            }
        }
    }
    std::cout << "\n";
}

bool Board::makeMove(int position, char symbol) {
    if (!isValidMove(position)) {
        return false;
    }
    cells[position] = symbol;
    return true;
}

bool Board::isValidMove(int position) const {
    return position >= 0 && position < 9 && cells[position] == ' ';
}

bool Board::isFull() const {
    for (const char& cell : cells) {
        if (cell == ' ') return false;
    }
    return true;
}

void Board::reset() {
    cells.fill(' ');
}

char Board::getCell(int position) const {
    if (position >= 0 && position < 9) {
        return cells[position];
    }
    return ' ';
}

char Board::checkWinner() const {
    // Winning combinations: rows, columns, diagonals
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };
    
    for (const auto& pattern : winPatterns) {
        if (cells[pattern[0]] != ' ' &&
            cells[pattern[0]] == cells[pattern[1]] &&
            cells[pattern[1]] == cells[pattern[2]]) {
            return cells[pattern[0]];
        }
    }
    return ' ';  // No winner
}

void Board::undoMove(int position) {
    if (position >= 0 && position < 9) {
        cells[position] = ' ';
    }
}

std::array<char, 9> Board::getCells() const {
    return cells;
}
