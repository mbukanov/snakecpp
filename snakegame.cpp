#include "snakegame.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

static struct termios stored_settings;

SnakeGame::SnakeGame(CScreen* screen) {
    this->screen = screen;
    snake = new Snake(screen);
    dot = new Dot(screen);
    field = new Field(screen);
    score = 0;
    dot->newDot();
}

SnakeGame::~SnakeGame() {
    delete snake;
    delete dot;
    delete field;
}

void SnakeGame::setKeypress() {
    struct termios new_settings;

	tcgetattr(0, &stored_settings);

	new_settings = stored_settings;

	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;

	tcsetattr(0,TCSANOW,&new_settings);
}


void SnakeGame::resetKeypress() {
    tcsetattr(0,TCSANOW,&stored_settings);
}

void SnakeGame::start() {
    setKeypress();
    fd_set rfds;
	struct timeval tv;
	int retval;
    char key;
    while(true) {
        FD_ZERO(&rfds);
	    FD_SET(0, &rfds);

        tv.tv_sec = 0;
	    tv.tv_usec = 0;	
        retval = select(2, &rfds, NULL, NULL, &tv);
	    if (retval) {
		    key = getc(stdin);
	    }

        if(key == KEY_UP) 
            snake->move(UP);
        else if(key == KEY_DOWN) 
            snake->move(DOWN);
        else if(key == KEY_LEFT)
            snake->move(LEFT);
        else if(key == KEY_RIGTH)
            snake->move(RIGHT);
        else if(key == KEY_PAUSE) {
            // TODO
        } else if(key == KEY_QUITE) {
            break;
        }
        

        if(field->isSnakeBreak(snake)) {
            break;
        }
        if(field->isSnakeOnDot(snake, dot)) {
            snake->addCell(dot->getPos());
            score++;
            dot->newDot();
        }

        field->draw(snake, dot, score);

        usleep(100000);
    }
    resetKeypress();
}
