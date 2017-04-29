#include "Wall.h"//F74024020
#include <ncurses.h>
    void Wall::PrtWall(int wx,int wy){
        init_pair(8, COLOR_WHITE, COLOR_WHITE);
        attrset(COLOR_PAIR(8)|A_BOLD);
        mvaddstr(wy, wx, "#");
        attrset(A_NORMAL);
        return;
    }
