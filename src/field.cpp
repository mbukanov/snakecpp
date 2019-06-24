#include "field.hpp"
#include <algorithm>

Field::Field(CScreen* screen) {
    this->screen = screen;
}

void Field::draw(Snake* snake, Dot* dot, int score) {
    std::list<std::pair<int, int>> temp = snake->getPos();
    screen->clearScreen();
    drawBorder();
    drawScore(score);

    while(!temp.empty()) {
        screen->putChar(temp.back().first, temp.back().second, SNAKE_CHAR);
        temp.pop_back();
    }

    if(dot->isExists())
        screen->putChar(dot->getPos().first, dot->getPos().second, DOT_CHAR);
}

void Field::drawBorder() {
    for(int i = 1; i <= screen->getWidth(); i++) {
        screen->setCursor(i, 1, '#');
        screen->setCursor(i, screen->getHeight(), '#');
    }

    for(int i = 1; i <= screen->getHeight(); i++) {
        screen->setCursor(1, i, '#');
        screen->setCursor(screen->getWidth(), i, '#');
    }
}

bool Field::isSnakeOnDot(Snake* snake, Dot* dot) {
    if(snake->getPos().front().first == dot->getPos().first && 
       snake->getPos().front().second == dot->getPos().second)
       return true;
    return false;
}

bool Field::isSnakeBreak(Snake* snake) {
    int x = snake->getPos().front().first;
    int y = snake->getPos().front().second;
    if(x < 1 || x > screen->getWidth())
        return true;
    if(y < 1 || y > screen->getHeight())
        return true;
    std::list<std::pair<int, int>> pos = snake->getPos();
    pos.pop_front();
    for(auto it = pos.begin(); it != pos.end(); it++) {
        if(it->first == x && it->second == y)
            return true;
    }

    return false;
}

void Field::drawScore(int score) {
    
    screen->putString(screen->getWidth()+10, 5, std::string("Score: " + std::to_string(score)));
}