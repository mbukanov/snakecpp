#include "snake.hpp"
#include <unistd.h>
#include <algorithm>

Snake::Snake(CScreen *screen) {
    this->screen = screen;
    int width = screen->getWidth();
    int height = screen->getHeight();
    pos.push_front(std::make_pair(width/2, height/2));
}

void Snake::move(int direction) {
    int x = pos.front().first;
    int y = pos.front().second;
    if(direction == UP) {
        x = x;
        y = y-1;
    } else if(direction == DOWN) {
        x = x;
        y = y+1;
    } else if(direction == RIGHT) {
        x = x+1;
        y = y;
    } else if(direction == LEFT) {
        x = x - 1;
        y = y;
    }

    
    std::pair<int, int> prev_cell = getPrevCell();
    if(exists(prev_cell.first, prev_cell.second)) {
        if(prev_cell.first == x && prev_cell.second == y)
            return; // We can't turn to 180 degree and continue moving
    }
    
    pos.pop_back();
    pos.push_front(std::make_pair(x, y));


}

std::list<std::pair<int,int>> Snake::getPos() {
    return pos;
}

void Snake::addCell(std::pair<int, int> cell) {
    pos.push_front(cell);
}

bool Snake::exists(int x, int y) {
    return std::find(pos.begin(), pos.end(), std::make_pair(x, y)) != pos.end();
}

std::pair<int, int> Snake::getPrevCell() {
    if(pos.size() > 1) {
        std::list<std::pair<int, int>> temp = pos;
        temp.pop_front();
        return std::make_pair(temp.front().first, temp.front().second);
    }
    return std::make_pair(-1, -1);
}

