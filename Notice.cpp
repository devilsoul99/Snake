#include "Notice.h"//F74024020
#include <ctime>
#include <ncurses.h>
    int Notice::GetPower(){
        return Power;
    }
    int Notice::Elapsed(){
        return time(NULL)-StartTime;
    }
    void Notice::GetMoney(){
        init_pair(5, COLOR_GREEN, COLOR_BLACK);
        attrset(COLOR_PAIR(5)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "GET MONEY!!!            ");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::Buy(){
        init_pair(5, COLOR_GREEN, COLOR_BLACK);
        attrset(COLOR_PAIR(5)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "Life +1 ,Score -10000!!!");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::NeedMore(){
        init_pair(6, COLOR_RED, COLOR_BLACK);
        attrset(COLOR_PAIR(6)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "NEED MORE SCORE!!!      ");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::EatPoi(){
        init_pair(6, COLOR_RED, COLOR_BLACK);
        attrset(COLOR_PAIR(6)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "Eat poison! Life -1!!!  ");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::HitWall(){
        init_pair(6, COLOR_RED, COLOR_BLACK);
        attrset(COLOR_PAIR(6)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "Hit The Wall! Life -1!!!");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::Accel(){
        init_pair(6, COLOR_RED, COLOR_BLACK);
        attrset(COLOR_PAIR(6)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "ACCELERATED!!!          ");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::SprLength(){
        init_pair(7, COLOR_BLUE, COLOR_BLACK);
        attrset(COLOR_PAIR(7)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "LENTH BOOST +3!!!       ");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::SprBonus(){
        init_pair(7, COLOR_BLUE, COLOR_BLACK);
        attrset(COLOR_PAIR(7)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "Bonus Time! Score X 1.5!");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::SprSuper(){
        init_pair(7, COLOR_BLUE, COLOR_BLACK);
        attrset(COLOR_PAIR(7)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "Super!No Death By Wall!!");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::GhostAppear(){
        init_pair(6, COLOR_RED, COLOR_BLACK);
        attrset(COLOR_PAIR(6)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "Ghost Appeared!!!       ");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::GhostBump(){
        init_pair(6, COLOR_RED, COLOR_BLACK);
        attrset(COLOR_PAIR(6)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "Bump into Ghost!!!      ");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::GhostEatMoney(){
        init_pair(6, COLOR_RED, COLOR_BLACK);
        attrset(COLOR_PAIR(6)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "Money has been eaten!!! ");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::GhostEliminate(){
        init_pair(5, COLOR_GREEN, COLOR_BLACK);
        attrset(COLOR_PAIR(5)|A_BLINK|A_BOLD);
        mvaddstr(1, 12, "Ghost Eliminated!!!     ");
        attrset(A_NORMAL);
        StartTime=time(NULL);
        Power=1;
    }
    void Notice::Off(){
        mvaddstr(1, 12, "                        ");
        Power=0;
    }
