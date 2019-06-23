#include "dot.hpp"
#include <cstdlib>

Dot::Dot(CScreen* screen) { 
    this->screen = screen; 
    exists = false;
}

void Dot::newDot() {
    x = rand() % (screen->getWidth()-3) + 3;
    y = rand() % (screen->getHeight()-3) + 3;
    exists = true;
}

void Dot::deleteDot() {
    exists = false;
}
