#include "SuperTimer.h"//F74024020
#include <ncurses.h>
    SuperTimer::SuperTimer(int a){
        width=a;
        Power=0;
    }
    void SuperTimer::SuperOn(int a){
        StartTime=a;
        Power=1;
    }
    void SuperTimer::SuperOff(){
        mvaddstr(1, width-33, "          ");
        Power=0;
    }
    void SuperTimer::ShowSecondsLeft(int a){
        init_pair(7, COLOR_BLUE, COLOR_BLACK);
        attrset(COLOR_PAIR(7)|A_BOLD);
        mvprintw(1, width-33, "Super: %d ",20-(a-StartTime));
        attrset(A_NORMAL);
    }
