#include "Game.h"
#include <iostream>

Game::Game(bool humanFirst) : gameOver(false) {
    if (humanFirst) {
        player1 = std::make_unique<HumanPlayer>('X');
        player2 = std::make_unique<AIPlayer>('O');
    } else {
        player1 = std::make_unique<AIPlayer>('X');
        player2 = std::make_unique<HumanPlayer>('O');
    }
    currentPlayer = player1.get();
}

void Game::switchTurn() {
    if (currentPlayer == player1.get()) {
        currentPlayer = player2.get();
    } else {
        currentPlayer = player1.get();
    }
}

void Game::displayResult() {
    char winner = board.checkWinner();
    
    std::cout << "\n══════════════════════\n";
    if (winner != ' ') {
        if ((winner == 'X' && dynamic_cast<HumanPlayer*>(player1.get())) ||
            (winner == 'O' && dynamic_cast<HumanPlayer*>(player2.get()))) {
            std::cout << "  🎉 YOU WIN! 🎉\n";
        } else {
            std::cout << "  💻 AI WINS! 💻\n";
        }
        std::cout << "  Player " << winner << " is victorious!\n";
    } else {
        std::cout << "  🤝 IT'S A DRAW! 🤝\n";
    }
    std::cout << "══════════════════════\n\n";
}

void Game::start() {
    std::cout << "\n╔═══════════════════════════╗\n";
    std::cout << "║   TIC-TAC-TOE vs AI       ║\n";
    std::cout << "║   Enter 1-9 to move       ║\n";
    std::cout << "╚═══════════════════════════╝\n";
    
    while (!gameOver) {
        board.display();
        
        int move = currentPlayer->getMove(board);
        board.makeMove(move, currentPlayer->getSymbol());
        
        // Check for winner
        if (board.checkWinner() != ' ') {
            board.display();
            gameOver = true;
            displayResult();
        }
        // Check for draw
        else if (board.isFull()) {
            board.display();
            gameOver = true;
            displayResult();
        }
        // Continue game
        else {
            switchTurn();
        }
    }
}
