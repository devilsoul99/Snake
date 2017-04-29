#include "Money.h"//F74024020
#include <ncurses.h>
Money::Money(int a,int b){
        Change(a,b);
}
void Money::Change(int a, int b){
        cx=a;cy=b;
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        attrset(COLOR_PAIR(2)|A_BOLD);
        mvaddstr(cy, cx, "$");
        attrset(A_NORMAL);
}
int Money::GetX(){
        return cx;
}
int Money::GetY(){
        return cy;
}
