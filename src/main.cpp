#include "snakegame.hpp"
#include "cscreen.hpp"

int main(int argc, char** argv) {

    CScreen screen(70, 40);

    SnakeGame game(&screen);
    game.start();

    return 0;
}