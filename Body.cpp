#include "Body.h"
#include <ncurses.h>//F74024020

Body::Body(int a,int b){
        cx=a;
        cy=b;
        mvaddstr(cy, cx, "O");//頭的樣子
    }
void Body::Change(){
        mvaddstr(cy, cx, "o");//身體
}
void Body::GiveWall(){//身體最後一節補上牆壁
        init_pair(8, COLOR_WHITE, COLOR_WHITE);
        attrset(COLOR_PAIR(8)|A_BOLD);
        mvaddstr(cy, cx, "#");
        attrset(A_NORMAL);
}
void Body::Clean(){
        mvaddstr(cy, cx, " ");//清除
}

int Body::GetX(){
        return cx;
}
int Body::GetY(){
        return cy;
}
