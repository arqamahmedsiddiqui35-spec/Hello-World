# Tic-Tac-Toe with AI Opponent

A console-based Tic-Tac-Toe game written in C++ featuring an **unbeatable AI** using the Minimax algorithm with alpha-beta pruning.

## 🎮 Features

- **Human vs AI gameplay** - Play as X (first) or O (second)
- **Unbeatable AI** - Uses Minimax algorithm to make optimal moves
- **Clean modular code** - Separated into header and source files
- **Input validation** - Handles invalid inputs gracefully
- **Play again option** - Multiple rounds without restarting

## 📁 Project Structure

```
├── include/
│   ├── Board.h      # Board state and display
│   ├── Player.h     # Human and AI player classes
│   └── Game.h       # Game loop and logic
├── src/
│   ├── Board.cpp
│   ├── Player.cpp
│   ├── Game.cpp
│   └── main.cpp     # Entry point
└── README.md
```

## 🔧 Building the Game

Make sure you have a C++ compiler installed (g++, clang++, or MSVC).

```bash
# Compile with g++
g++ -I include src/*.cpp -o tictactoe

# On Windows
g++ -I include src/*.cpp -o tictactoe.exe
```

## 🚀 Running the Game

```bash
./tictactoe        # Linux/Mac
tictactoe.exe      # Windows
```

## 🎯 How to Play

1. Choose to play as **X** (go first) or **O** (AI goes first)
2. Enter a number **1-9** to place your mark:

```
  1 │ 2 │ 3
 ───┼───┼───
  4 │ 5 │ 6
 ───┼───┼───
  7 │ 8 │ 9
```

3. Try to beat the AI (hint: you can't, but you can tie!)

## 📚 Learning Points

This project demonstrates:
- **Object-Oriented Programming** - Classes, inheritance, polymorphism
- **Header/Source separation** - Proper C++ project structure
- **Minimax Algorithm** - Game theory and AI decision making
- **Alpha-Beta Pruning** - Optimization of recursive algorithms

## License

MIT License - See [LICENSE](LICENSE) for details.