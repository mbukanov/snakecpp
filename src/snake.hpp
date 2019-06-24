#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "cscreen.hpp"
#include <list>

enum { UP, DOWN, LEFT, RIGHT };


class Snake {
public:
    Snake(CScreen *screen);
    void move(int direction);
    std::list<std::pair<int,int>> getPos();
    void addCell(std::pair<int, int> cell);
    std::pair<int, int> getPrevCell();
    bool exists(int x, int y);



private:
    CScreen* screen;
    std::list<std::pair<int, int>> pos;
};

#endif