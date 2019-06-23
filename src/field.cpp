#include "field.hpp"

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
    if(snake->getPos().front().first < 1 || snake->getPos().front().first > screen->getWidth())
        return true;
    if(snake->getPos().front().second < 1 || snake->getPos().front().second > screen->getHeight())
        return true;
    return false;
}

void Field::drawScore(int score) {
    
    screen->putString(screen->getWidth()+10, 5, std::string("Score: " + std::to_string(score)));
}