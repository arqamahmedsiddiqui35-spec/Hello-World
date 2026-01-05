#include "Player.h"
#include <iostream>
#include <limits>

// =====================
// Base Player Class
// =====================

Player::Player(char sym) : symbol(sym) {
    opponentSymbol = (sym == 'X') ? 'O' : 'X';
}

char Player::getSymbol() const {
    return symbol;
}

// =====================
// Human Player
// =====================

HumanPlayer::HumanPlayer(char sym) : Player(sym) {}

int HumanPlayer::getMove(Board& board) {
    int move;
    
    while (true) {
        std::cout << "Player " << symbol << ", enter your move (1-9): ";
        std::cin >> move;
        
        // Handle invalid input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        // Convert 1-9 to 0-8 index
        move--;
        
        if (board.isValidMove(move)) {
            return move;
        }
        
        std::cout << "Invalid move! Cell is already taken or out of range.\n";
    }
}

// =====================
// AI Player (Minimax)
// =====================

AIPlayer::AIPlayer(char sym) : Player(sym) {}

int AIPlayer::minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta) {
    char winner = board.checkWinner();
    
    // Terminal states
    if (winner == symbol) return 10 - depth;        // AI wins
    if (winner == opponentSymbol) return depth - 10; // Opponent wins
    if (board.isFull()) return 0;                   // Draw
    
    if (isMaximizing) {
        int maxEval = -1000;
        for (int i = 0; i < 9; i++) {
            if (board.isValidMove(i)) {
                board.makeMove(i, symbol);
                int eval = minimax(board, depth + 1, false, alpha, beta);
                board.undoMove(i);
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if (beta <= alpha) break;  // Alpha-beta pruning
            }
        }
        return maxEval;
    } else {
        int minEval = 1000;
        for (int i = 0; i < 9; i++) {
            if (board.isValidMove(i)) {
                board.makeMove(i, opponentSymbol);
                int eval = minimax(board, depth + 1, true, alpha, beta);
                board.undoMove(i);
                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);
                if (beta <= alpha) break;  // Alpha-beta pruning
            }
        }
        return minEval;
    }
}

int AIPlayer::getMove(Board& board) {
    std::cout << "AI (" << symbol << ") is thinking...\n";
    
    int bestMove = -1;
    int bestScore = -1000;
    
    for (int i = 0; i < 9; i++) {
        if (board.isValidMove(i)) {
            board.makeMove(i, symbol);
            int score = minimax(board, 0, false, -1000, 1000);
            board.undoMove(i);
            
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    
    return bestMove;
}
