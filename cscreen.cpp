#include "cscreen.hpp"
#include <string>
#include <iostream>

CScreen::CScreen(int width, int height) {
    this->width = width;
    this->height = height;
    clearScreen();
}

void CScreen::putChar(int x, int y, char c) {
    setCursor(x, y, c);
    setCursor(1, height+1, 0);
}

void CScreen::putString(int x, int y, std::string str) {
    setCursor(x, y);
    std::cout << str << std::flush;
    setCursor(1, height+1, 0);
}

void CScreen::setCursor(int x, int y, char c) {
    std::string res = "\033[" + std::to_string(y) + ";" + std::to_string(x) + "f";
    std::cout << res << c << std::flush;
}

void CScreen::setCursor(int x, int y) {
    std::string res = "\033[" + std::to_string(y) + ";" + std::to_string(x) + "f";
    std::cout << res << std::flush;
}

void CScreen::clearScreen() {
    std::cout << " \033[2J" << std::flush;
}
