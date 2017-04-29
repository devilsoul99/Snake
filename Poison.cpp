#include "Poison.h"//F74024020
#include <ncurses.h>
Poison::Poison(int a,int b,int apt){
        Change(a,b,apt);
}
void Poison::Change(int a, int b,int apt){
        cx=a;cy=b;AppearTime=apt;
        init_pair(3, COLOR_RED, COLOR_BLACK);
        attrset(COLOR_PAIR(3)|A_BOLD);
        mvaddstr(cy, cx, "$");
        attrset(A_NORMAL);
}
void Poison::Clean(){
        mvaddstr(cy, cx, " ");
    }
int Poison::GetX(){
        return cx;
}
int Poison::GetY(){
        return cy;
}
int Poison::GetAPT(){
        return AppearTime;
}
