#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include <memory>

class Game {
private:
    Board board;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    Player* currentPlayer;
    bool gameOver;

    void switchTurn();
    void displayResult();

public:
    Game(bool humanFirst);
    void start();
};

#endif // GAME_H
