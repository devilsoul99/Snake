#include "Surprise.h"//F74024020
#include <ncurses.h>
    Surprise::Surprise(int a,int b,int apt){
        Change(a,b,apt);
    }
    void Surprise::Change(int a, int b,int apt){
        cx=a;cy=b;AppearTime=apt;
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        attrset(COLOR_PAIR(4)|A_BOLD);
        mvaddstr(cy, cx, "?");
        attrset(A_NORMAL);
    }
    void Surprise::Clean(){
        mvaddstr(cy, cx, " ");
    }
    int Surprise::GetX(){
        return cx;
    }
    int Surprise::GetY(){
        return cy;
    }
    int Surprise::GetAPT(){
        return AppearTime;
    }
