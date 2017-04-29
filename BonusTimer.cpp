#include "BonusTimer.h"//F74024020
#include <ncurses.h>


    BonusTimer::BonusTimer(int a){
        width=a;
        Power=0;
    }
    void BonusTimer::BonusOn(int a){
        StartTime=a;
        Power=1;
    }
    void BonusTimer::BonusOff(){
        mvaddstr(1, width-23, "          ");
        Power=0;
    }
    void BonusTimer::ShowSecondsLeft(int a){
        init_pair(7, COLOR_BLUE, COLOR_BLACK);
        attrset(COLOR_PAIR(7)|A_BOLD);
        mvprintw(1, width-23, "Bonus: %d ",20-(a-StartTime));
        attrset(A_NORMAL);
    }
