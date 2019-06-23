#ifndef CSCREEN_HPP
#define CSCREEN_HPP
#include <stdio.h>
#include <string>

class CScreen {
public:
    CScreen(int width, int height);
    void putChar(int x, int y, char c);
    void putString(int x, int y, std::string str);

    void setCursor(int x, int y, char c);
    void setCursor(int x, int y);
    void clearScreen();

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width;
    int height;
};

#endif