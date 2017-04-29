#include "Ghost.h"//F74024020
#include <ncurses.h>
void Ghost::Appear(double a,double b,int t){
        GX=a;
        GY=b;
        ApT=t;
        init_pair(10, COLOR_CYAN, COLOR_BLACK);
        attrset(COLOR_PAIR(10)|A_BOLD);
        mvaddstr(GY, GX, "G");
        attrset(A_NORMAL);
}
void Ghost::GhostBye(){
        mvaddstr(GY, GX, " ");
        GX=-4;
        GY=-4;
}
void Ghost::SetPosition(int a,int b){
        mvaddstr(GY, GX, " ");
        GY=b;GX=a;
        init_pair(10, COLOR_CYAN, COLOR_BLACK);
        attrset(COLOR_PAIR(10)|A_BOLD);
        mvaddstr(GY, GX, "G");
        attrset(A_NORMAL);
}
void Ghost::GhostMove(double SnakeX,double SnakeY){//往蛇頭的方向移動
        if(WCK==1){
            init_pair(8, COLOR_WHITE, COLOR_WHITE);
            attrset(COLOR_PAIR(8)|A_BOLD);
            mvaddstr(GY, GX, "#");
            attrset(A_NORMAL);
            WCK=0;
        }
        else{mvaddstr(GY, GX, " ");}
        if(SnakeX>GX){
            GX += 0.00007;
        }
        else{
            GX += -0.00007;
        }
        if(SnakeY>GY){
            GY += 0.00005;
        }
        else{
            GY += -0.00005;
        }
        init_pair(10, COLOR_CYAN, COLOR_BLACK);
        attrset(COLOR_PAIR(10)|A_BOLD);
        mvaddstr(GY, GX, "G");
        attrset(A_NORMAL);
}
void Ghost::SetCheck(){
        WCK=1;
}
int Ghost::GetX(){
        return GX;
}
int Ghost::GetY(){
        return GY;
}
int Ghost::GetApT(){
        return ApT;
}
