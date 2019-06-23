#ifndef FIELD_HPP
#define FIELD_HPP

#include "cscreen.hpp"
#include "keyboard.hpp"
#include "snake.hpp"
#include "dot.hpp"

#define SNAKE_CHAR 'o'
#define DOT_CHAR 'z'

class Field  {
public:
    Field(CScreen* screen);
    void draw(Snake* snake, Dot* dot, int score);
    void drawBorder();
    void drawScore(int score);


    bool isSnakeBreak(Snake* snake);
    bool isSnakeOnDot(Snake* snake, Dot* dot);

private:
    CScreen* screen;
};

#endif