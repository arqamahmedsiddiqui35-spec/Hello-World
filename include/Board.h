#ifndef BOARD_H
#define BOARD_H

#include <array>

class Board {
private:
    std::array<char, 9> cells;  // 3x3 grid stored as 1D array

public:
    Board();
    
    void display() const;
    bool makeMove(int position, char symbol);
    bool isValidMove(int position) const;
    bool isFull() const;
    void reset();
    char getCell(int position) const;
    char checkWinner() const;
    
    // For AI to simulate moves
    void undoMove(int position);
    std::array<char, 9> getCells() const;
};

#endif // BOARD_H
