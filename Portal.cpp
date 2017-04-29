#include "Portal.h"//F74024020
#include <ncurses.h>
    void Portal::PrtPortal(int x1,int y1,int x2,int y2){
        init_pair(11, COLOR_YELLOW, COLOR_BLACK);
        attrset(COLOR_PAIR(11)|A_BOLD);
        mvaddstr(y1, x1, "@");
        mvaddstr(y2, x2, "@");
        attrset(A_NORMAL);
        return;
    }
