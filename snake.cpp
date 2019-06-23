#include "snake.hpp"
#include <unistd.h>

Snake::Snake(CScreen *screen) {
    this->screen = screen;
    int width = screen->getWidth();
    int height = screen->getHeight();
    pos.push_front(std::make_pair(width/2, height/2));
}

void Snake::move(int direction) {
    int x = pos.front().first;
    int y = pos.front().second;
    pos.pop_back();
    if(direction == UP) {
        pos.push_front(std::make_pair(x, y-1));
    } else if(direction == DOWN) {
        pos.push_front(std::make_pair(x, y+1));
    } else if(direction == RIGHT) {
        pos.push_front(std::make_pair(x+1, y));
    } else if(direction == LEFT) {
        pos.push_front(std::make_pair(x-1, y));
    }
}

std::list<std::pair<int,int>> Snake::getPos() {
    return pos;
}

void Snake::addCell(std::pair<int, int> cell) {
    pos.push_front(cell);
}