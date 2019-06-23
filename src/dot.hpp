#ifndef DOT_HPP
#define DOT_HPP

#include <utility>
#include "cscreen.hpp"

class Dot {
public:
    Dot(CScreen* screen);
    void newDot();
    void deleteDot();
    std::pair<int, int> getPos() { return std::make_pair(x, y); }
    bool isExists() { return exists; }

private:
    CScreen* screen;
    bool exists;
    int x, y;
};
#endif