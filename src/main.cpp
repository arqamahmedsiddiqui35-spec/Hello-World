#include "Game.h"
#include <iostream>
#include <limits>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    char playAgain = 'y';
    
    std::cout << "\n";
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║                                       ║\n";
    std::cout << "║       WELCOME TO TIC-TAC-TOE          ║\n";
    std::cout << "║          vs UNBEATABLE AI             ║\n";
    std::cout << "║                                       ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n";
    
    while (playAgain == 'y' || playAgain == 'Y') {
        int choice;
        
        std::cout << "\nChoose your side:\n";
        std::cout << "  1. Play as X (go first)\n";
        std::cout << "  2. Play as O (AI goes first)\n";
        std::cout << "\nEnter choice (1 or 2): ";
        std::cin >> choice;
        
        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            clearInput();
            choice = 1;  // Default to X
            std::cout << "Defaulting to X (first).\n";
        }
        
        bool humanFirst = (choice == 1);
        
        Game game(humanFirst);
        game.start();
        
        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
        clearInput();
    }
    
    std::cout << "\nThanks for playing! Goodbye.\n\n";
    return 0;
}
