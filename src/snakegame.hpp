#ifndef SNAKEGAME_HPP
#define SNAKEGAME_HPP

#include "cscreen.hpp"
#include "snake.hpp"
#include "dot.hpp"
#include "field.hpp"
#include "keyboard.hpp"

class SnakeGame {
public:
    SnakeGame(CScreen* screen);
    ~SnakeGame();
    void start();
    void setKeypress();
    void resetKeypress();

private:
    CScreen* screen;
    Snake* snake;
    Dot* dot;
    Field* field;
    int score;
    bool isPause;
};

#endif