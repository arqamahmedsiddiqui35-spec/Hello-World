#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

// Base Player class
class Player {
protected:
    char symbol;
    char opponentSymbol;

public:
    Player(char sym);
    virtual ~Player() = default;
    
    char getSymbol() const;
    virtual int getMove(Board& board) = 0;
};

// Human player - gets input from console
class HumanPlayer : public Player {
public:
    HumanPlayer(char sym);
    int getMove(Board& board) override;
};

// AI player - uses Minimax algorithm
class AIPlayer : public Player {
private:
    int minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta);
    
public:
    AIPlayer(char sym);
    int getMove(Board& board) override;
};

#endif // PLAYER_H
