#include "Body.h"
#include "BonusTimer.h"
#include "Ghost.h"
#include "Money.h"
#include "Notice.h"
#include "Poison.h"
#include "Portal.h"
#include "SuperTimer.h"
#include "Surprise.h"
#include "Timer.h"
#include "Wall.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <ctime>

void GameOver(int Score){//結算畫面
    clear();
    nodelay(stdscr, FALSE);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    attrset(COLOR_PAIR(3)|A_BOLD);
    mvaddstr(0, 0, "Game Over!!!");
    attrset(A_NORMAL);
    mvprintw(1, 0, "Your Score: %d",Score);
    mvaddstr(2, 0, "Press Any Key To Continue.");
    getch();
    endwin();
    exit(0);
}

void Pause(int width,int pt){//暫停
    init_pair(9, COLOR_RED, COLOR_WHITE);
    attrset(COLOR_PAIR(9)|A_BOLD);
    mvprintw(1, width-13, "Paused.     ");//暫停訊息 覆蓋時間
    int c;
    while ((time(NULL)-pt)<1||(c = getch()) != 'p'){//跑無限迴圈直到按下一次P
    }
    return;
}

void SetMap(int width,int height,int *Map,int Stage){//設置地圖牆壁
    Wall W;
    Portal P;
    int i,j;
    for(i=0;i<width*height;i++){
        *(Map+i)=0;
    }
    switch(Stage){
        case 1:{return;}
        case 2:{
            int y=((height-2)/2)+2;
            int x;
            for (x=0;x<width;x++){
                W.PrtWall(x,y);
                *(Map+(x*height+y))=1;
            }
            return;
        }
        case 3:{
            int y=((height-2)/2)+2;
            int x;
            for (x=0;x<width;x++){
                W.PrtWall(x,y);
                *(Map+(x*height+y))=1;
            }
            x=width/2;
            for (y=2;y<height;y++){
                W.PrtWall(x,y);
                *(Map+(x*height+y))=1;
            }
            return;
        }
        case 4:{
            int y;
            int x;
            y=((height-2)*2/3)+2;
            for(x=0;x<width;x++){
                W.PrtWall(x,y);
                *(Map+(x*height+y))=1;
            }
            x=width*2/3;
            for(y=2;y<=height*3/4;y++){
                W.PrtWall(x,y);
                *(Map+(x*height+y))=1;
            }
            x=width/3;
            for(y=height/4;y<=height;y++){
                W.PrtWall(x,y);
                *(Map+(x*height+y))=1;
            }
            int ay=((height-2)/6)+2;
            int ax=width*5/6;
            y=((height-2)*5/6)+2;
            x=width/6;
            P.PrtPortal(ax,ay,x,y);
            *(Map+(ax*height+ay))=2;
            *(Map+(x*height+y))=2;
            return;
        }
        case 5:{
            int y,x;
            for(x=0;x<=width;x++){
                W.PrtWall(x,2);
                *(Map+(x*height+2))=1;
                W.PrtWall(x,height-1);
                *(Map+(x*height+height-1))=1;
            }
            for(y=2;y<=height;y++){
                W.PrtWall(0,y);
                *(Map+y)=1;
                W.PrtWall(width-1,y);
                *(Map+((width-1)*height+y))=1;
            }
            x=width/5-5;
            for(y=((height-2)/4)+2;y<=((height-2)*3/4)+2;y++){
                W.PrtWall(x,y);
                *(Map+(x*height+y))=1;
                x+=5;
            }
            x=width*4/5+5;
            for(y=((height-2)/4)+2;y<=((height-2)*3/4)+2;y++){
                W.PrtWall(x,y);
                *(Map+(x*height+y))=1;
                x-=5;
            }
            return;
        }
        case 6:{
            int y,x;
            for(y=0;y<height;y++){
                for(x=0;x<width;x++){
                    if((y+x)%22==0&&y>1){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                }
            }
            return;
        }
        case 7:{
            int y,x;
            for(y=0;y<height;y++){
                for(x=0;x<width;x++){
                    if(((y-((height-2)/2))*(y-((height-2)/2)))+((x-(width/2))*(x-(width/2)))>36&&((y-((height-2)/2))*(y-((height-2)/2)))+((x-(width/2))*(x-(width/2)))<49&&y>1){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if(((y-((height-2)/2))*(y-((height-2)/2)))+((x-(width/2))*(x-(width/2)))>184&&((y-((height-2)/2))*(y-((height-2)/2)))+((x-(width/2))*(x-(width/2)))<225&&y>1){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if(((y-((height-2)/2))*(y-((height-2)/2)))+((x-(width/2))*(x-(width/2)))>700&&((y-((height-2)/2))*(y-((height-2)/2)))+((x-(width/2))*(x-(width/2)))<800&&y>1){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                }
            }
            int ay=((height-2)/4)+2;
            int ax=width/2-35;
            y=((height-2)/2);
            x=width/2;
            P.PrtPortal(ax,ay,x,y);
            *(Map+(ax*height+ay))=2;
            *(Map+(x*height+y))=2;
            ay=((height-2)*3/4)+2;
            ax=width/2+35;
            y=((height-2)/5);
            x=width/2+18;
            P.PrtPortal(ax,ay,x,y);
            *(Map+(ax*height+ay))=3;
            *(Map+(x*height+y))=3;
            y=((height-2)*4/5);
            ay=((height-2)*3/4)+2;
            ax=width/2-18;
            P.PrtPortal(ax,ay,x,y);
            *(Map+(ax*height+ay))=4;
            *(Map+(x*height+y))=4;
            return;
        }
        case 8:{
            int y,x,ax,ay;
            for(y=0;y<height;y++){
                for(x=0;x<width;x++){
                    if(((x-(width/2))*(x-(width/2)))-((y-((height-2)/2))*(y-((height-2)/2)))<35&&((x-(width/2))*(x-(width/2)))-((y-((height-2)/2))*(y-((height-2)/2)))>7&&y>1){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if(x==14&&y>height-6){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if(x<12&&y==height-6){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if(x==0&&y>height-6){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if(x<=14&&y==height-1){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if(x+y==18&&y>1){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if(x>width-26&&y==(height-2)/2+2){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if(y>1&&y<(height-2)/3+2&&x==width-22){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                    if((y+x)%48<8&&y>1&&x>10){*(Map+(x*height+y))=1;W.PrtWall(x,y);}
                }
            }
            y=height-3;
            x=4;
            ay=2;
            ax=width/2+2;
            P.PrtPortal(ax,ay,x,y);
            *(Map+(ax*height+ay))=2;
            *(Map+(x*height+y))=2;
            y=2;
            x=5;
            ay=height-1;
            ax=15;
            P.PrtPortal(ax,ay,x,y);
            *(Map+(ax*height+ay))=3;
            *(Map+(x*height+y))=3;
            return;
        }
    }
}

void Description(int &Stage,int &width,int &height){//說明頁面 選擇難度
    int c ,select=1;
    initscr();
    start_color();
    mvaddstr(0, 0, "Hello! Wellcome to LoserSnake Game!!!");
    mvaddstr(1, 0, "Now some information for you:");
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    attrset(COLOR_PAIR(2)|A_BOLD);
    mvaddstr(3, 3, "$");
    attrset(A_NORMAL);
    mvaddstr(3, 5, "- Good money. Your snake gets longer and earn score.");
    init_pair(3, COLOR_RED, COLOR_BLACK);
    attrset(COLOR_PAIR(3)|A_BOLD);
    mvaddstr(5, 3, "$");
    attrset(A_NORMAL);
    mvaddstr(5, 5, "- Poison money. YOU EAT IT, YOU DIE!");
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    attrset(COLOR_PAIR(4)|A_BOLD);
    mvaddstr(7, 3, "?");
    attrset(A_NORMAL);
    mvaddstr(7, 5, "- Something SURPRISE. One of the following effects occurs:");
    mvaddstr(8, 7, "1.The snake becomes longer.");
    mvaddstr(9, 7, "2.Super Power: Your snake can go through wall without dying.");
    mvaddstr(10, 9, "(still die if you eat youself or poison.)");
    mvaddstr(11, 7, "3.Bonus Time: You get extra 50% score from eating good money");
    mvaddstr(12, 9, "for the following 20 seconds.");
    init_pair(10, COLOR_CYAN, COLOR_BLACK);
    attrset(COLOR_PAIR(10)|A_BOLD);
    mvaddstr(14, 3, "G");
    attrset(A_NORMAL);
    mvaddstr(14, 5, "- The Ghost. It appears after level 10 and start chasing you.");
    mvaddstr(15, 7, "If it got to your head, your score will be reduced by half.");
    mvaddstr(16, 7, "If it got the money, your score -3000 for each.");
    mvaddstr(17, 7, "Try leading it to a poison(3000 score for killing it).");
    init_pair(11, COLOR_YELLOW, COLOR_BLACK);
    attrset(COLOR_PAIR(11)|A_BOLD);
    mvaddstr(19, 3, "@");
    attrset(A_NORMAL);
    mvaddstr(19, 5, "- Portal. Transports you to another corresponding portal.");
    attrset(A_BOLD);
    mvaddstr(21, 3, "You can buy an extra life by pressing B (cost 10000 score).");
    mvaddstr(22, 3, "Press any key to continue.");
    getch();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    getmaxyx(stdscr, height, width);//取得長寬
    mvprintw(0, 0, "Please select stage(1~5): %d",Stage);
    mvaddstr(1, 0, "(Use the left/right arrow key. Up arrow to start. Esc to leave.)");
    curs_set(0);
    int ShowMap[width][height];
    SetMap(width,height,&ShowMap[0][0],Stage);
    time_t timecheck=0;
    while (select){
        while ((c = getch()) == ERR){
            attrset(A_BOLD);
            mvprintw(0, 0, "Please select stage(1~8): %d",Stage);
            mvaddstr(1, 0, "(Use the left/right arrow key. Up arrow to start. Esc to leave.)");
        }
        switch (c) {
            case KEY_LEFT:
                if(Stage>1&&time(NULL)-timecheck>=1){Stage--;clear();timecheck=time(NULL);SetMap(width,height,&ShowMap[0][0],Stage);break;}//防止連按
                if(Stage==1&&time(NULL)-timecheck>=1){Stage=8;clear();timecheck=time(NULL);SetMap(width,height,&ShowMap[0][0],Stage);break;}
                break;
            case KEY_RIGHT:
                if(Stage<8&&time(NULL)-timecheck>=1){Stage++;clear();timecheck=time(NULL);SetMap(width,height,&ShowMap[0][0],Stage);break;}
                if(Stage==8&&time(NULL)-timecheck>=1){Stage=1;clear();timecheck=time(NULL);SetMap(width,height,&ShowMap[0][0],Stage);break;}
                break;
            case 27://esc
                endwin();
                exit(0);
            case KEY_UP:
                clear(); return;
            default: ;
        }
    }
    return;
}

int main(){
    int width, height;
    double u, v, x, y;
    int c, go_on, Stage=2;
    Description(Stage,width,height);//選擇難度
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);//遊戲介面
    attrset(COLOR_PAIR(1)|A_BOLD);
    mvaddstr(0, 0, "Arrow: Move P: Pause");
    mvaddstr(1, 0, "ESC: Quit");
    attrset(A_NORMAL);
    u = 1;v = 0; x = 3; y = 3; go_on = 1;//遊戲元件設置
    int bx,by;
    int MaxBody=5;
    int Score=0;
    int Xspeed=8000,Yspeed=12000;
    int Accelcheck=0;
    int Level=1;
    int Life=1;
    int BonusTime=0;
    int BonusStart;
    int SuperTime=0;
    int SuperStart;//創造驚喜物件
    int GameTime;
    int LifeCheck=0;
    int k;
    int GhostOn=0;
    std::vector<Body> Snake;
    Body Head(-2,-2);//先設一節(用不到) 為了之後用insert
    Snake.push_back(Head);
    Timer clock;//創造遊戲計時器
    Money Mny(10,10);//創造金幣物件
    Poison Psn(-1,-1,0);//創造毒藥物件
    Notice Nt;//創造告示燈物件
    Surprise Spr(-1,-1,0);//創造驚喜物件
    BonusTimer BTr(width);//創造獎勵計時器
    SuperTimer SpTmr(width);//創造無敵計時器
    Ghost Ghst;//創造鬼魂物件
    int WallMap[width][height];
    SetMap(width,height,&WallMap[0][0],Stage);
    while (go_on) {//遊戲進行中
        curs_set(0);
        while ((c = getch()) == ERR) { //沒輸入控制鍵
            GameTime=clock.GetTime();
            attrset(COLOR_PAIR(1)|A_BOLD);
            mvprintw(0, width-13, "Score: %d  ",Score);//遊戲浮動數據  分數
            mvprintw(1, width-13, "Timer: %d   ",GameTime);//時間
            mvprintw(0, width-23, "Level: %d",Level);//加速數
            mvprintw(0, width-33, "Stage: %d",Stage);//關卡
            mvprintw(0, width-42, "Life: %d",Life);//命數
            if(BonusTime==1){BTr.ShowSecondsLeft(GameTime);}//獎勵倒數時間
            if(SuperTime==1){SpTmr.ShowSecondsLeft(GameTime);}//無敵倒數時間
            if(Score>10000){mvaddstr(0, 22, "B: Buy life");}
            attrset(A_NORMAL);
            if(GameTime%30==0&&GameTime!=0&&Accelcheck==0){//每30秒加速
                Xspeed=(int)Xspeed*0.92;
                Yspeed=(int)Yspeed*0.9;
                Accelcheck=1;
                Level++;
                Nt.Accel();
            }
            if(GameTime%30==1&&GameTime!=1&&Accelcheck==1){//防止多重加速
                Accelcheck=0;
            }
            if(Nt.Elapsed()>3&&Nt.GetPower()==1){//告示燈關閉
                Nt.Off();
            }
            {//蛇移動
            bx=x;by=y;
            x += u/Xspeed;
            y += v/Yspeed;
            while (x < 0) x += width;
            while (x >= width) x -= width;
            while (y <2) y = height;
            while (y > height) y = 2;}//移動結束
            if(((int)x==Mny.GetX())&&(int)y==(Mny.GetY())){//吃到金幣
                if(BonusTime==1){
                    Score+=150;
                }
                else{
                    Score+=100;
                }
                MaxBody++;
                Nt.GetMoney();
                Mny.Change(-5,-5);
                int mx,my,check,i,j,checkfor;
                srand((unsigned)time(NULL));//種子
                check=0;
                checkfor=0;
                while(check==0){//檢查物件位置有無重複
                    mx=(rand()+GameTime)%width;
                    my=rand()%(height-2)+2;
                    if(mx==Psn.GetX()&&my==Psn.GetY()){continue;}
                    if(mx==Spr.GetX()&&my==Spr.GetY()){continue;}
                    if(mx==Ghst.GetX()&&my==Ghst.GetY()){continue;}
                    if(WallMap[mx][my]!=0){continue;}
                    for(i=0;i<=Snake.size();i++){
                        if(mx==Snake[i].GetX()&&my==Snake[i].GetY()){checkfor=1;break;}
                    }
                    if(checkfor==1){checkfor=0;continue;}
                    check=1;
                }
                Mny.Change(mx,my);//改金幣位置
            }
            if(((int)x==Psn.GetX())&&(int)y==(Psn.GetY())){//吃到毒藥
                Life--;
                Psn.Change(-1,-1,GameTime);
                Nt.EatPoi();
            }
            if(WallMap[(int)x][(int)y]==1&&SuperTime==0&&LifeCheck==0){//蛇撞到牆
                Life--;
                LifeCheck=1;
                Nt.HitWall();
            }
            if(LifeCheck==1&&WallMap[(int)x][(int)y]!=1){//防止多重扣命
                LifeCheck=0;
            }
            if(((int)x==Spr.GetX())&&(int)y==(Spr.GetY())){//吃到驚喜
                srand((unsigned)time(NULL));//種子
                int kind=rand()%3;
                if(kind==0){//加長3格
                    MaxBody+=3;
                    Spr.Clean();
                    Spr.Change(-1,-1,GameTime);
                    Nt.SprLength();
                    Score+=1000;
                }
                if(kind==1){//獎勵時間二十秒
                    BonusTime=1;
                    BonusStart=GameTime;
                    BTr.BonusOn(GameTime);
                    Spr.Clean();
                    Spr.Change(-1,-1,GameTime);
                    Nt.SprBonus();
                    Score+=1000;
                }
                if(kind==2){//無敵時間二十秒
                    SuperTime=1;
                    SuperStart=GameTime;
                    SpTmr.SuperOn(GameTime);
                    Spr.Clean();
                    Spr.Change(-1,-1,GameTime);
                    Nt.SprSuper();
                    Score+=1000;
                }
            }
            if(BonusTime==1&&GameTime-BonusStart>=20){//關閉獎勵時間
                BonusTime=0;
                BTr.BonusOff();
            }
            if(SuperTime==1&&GameTime-SuperStart>=20){//關閉無敵時間
                SuperTime=0;
                SpTmr.SuperOff();
            }
            for(k=1;k<=Snake.size();k++){//撞到自己
                if((int)x==Snake[k].GetX()&&(int)y==Snake[k].GetY()){
                    GameOver(Score);
                }
            }
            if(WallMap[(int)x][(int)y]>1){//進入傳送門
                int Number=WallMap[(int)x][(int)y];
                int i,j,ax,ay;
                for(i=0;i<width;i++){
                    for(j=0;j<height;j++){
                        if(WallMap[i][j]==Number&&i!=(int)x&&j!=(int)y){ax=i;ay=j;}
                    }
                }
                x=ax+u;y=ay+v;
            }
            srand((unsigned)time(NULL));
            if(rand()%15==1&&Psn.GetX()<=-1){//決定是否出現毒藥
                    int px,py,check,i,j,checkfor;
                    srand((unsigned)time(NULL));//種子
                    check=0;
                    checkfor=0;
                    while(check==0){//檢查物件位置有無重複
                        px=(rand()-GameTime)%width;
                        py=rand()%(height-2)+2;
                        if(px==Mny.GetX()&&py==Mny.GetY()){continue;}
                        if(px==Spr.GetX()&&py==Spr.GetY()){continue;}
                        if(px==Ghst.GetX()&&py==Ghst.GetY()){continue;}
                        if(WallMap[px][py]!=0){continue;}
                        for(i=0;i<=Snake.size();i++){
                            if(px==Snake[i].GetX()&&py==Snake[i].GetY()){checkfor=1;break;}
                        }
                        if(checkfor==1){checkfor=0;continue;}
                        check=1;
                    }
                    Psn.Change(px,py,GameTime);
            }
            if(Psn.GetX()!=-1&&GameTime-Psn.GetAPT()>=15){//毒藥在場面上且經過了15秒 消失
                Psn.Clean();
                Psn.Change(-1,-1,GameTime);
            }
            if(rand()%37==1&&Spr.GetX()<=-1){//決定是否出現驚喜
                    int sx,sy,check,i,j,checkfor;
                    srand((unsigned)time(NULL));//種子
                    check=0;
                    checkfor=0;
                    while(check==0){//檢查物件位置有無重複
                        sx=(rand()-GameTime)%width;
                        sy=rand()%(height-2)+2;
                        if(sx==Mny.GetX()&&sy==Mny.GetY()){continue;}
                        if(sx==Psn.GetX()&&sy==Psn.GetY()){continue;}
                        if(sx==Ghst.GetX()&&sy==Ghst.GetY()){continue;}
                        if(WallMap[sx][sy]!=0){continue;}
                        for(i=0;i<=Snake.size();i++){
                            if(sx==Snake[i].GetX()&&sy==Snake[i].GetY()){checkfor=1;break;}
                        }
                        if(checkfor==1){checkfor=0;continue;}
                        check=1;
                    }
                    Spr.Change(sx,sy,GameTime);
            }
            if(Spr.GetX()!=-1&&GameTime-Spr.GetAPT()>=10){//驚喜在場面上且經過了10秒 消失
                Spr.Clean();
                Spr.Change(-1,-1,GameTime);
            }
            if(Level>=10&&rand()%17==1&&GhostOn==0){//決定是否出現鬼
                    GhostOn=1;
                    int sx,sy,check,i,j,checkfor;
                    check=0;
                    checkfor=0;
                    while(check==0){//檢查物件位置有無重複
                        sx=(rand()-GameTime)%width;
                        sy=rand()%(height-2)+2;
                        if(sx==Mny.GetX()&&sy==Mny.GetY()){continue;}
                        if(sx==Psn.GetX()&&sy==Psn.GetY()){continue;}
                        if(sx==Spr.GetX()&&sy==Spr.GetY()){continue;}
                        if(WallMap[sx][sy]!=0){continue;}
                        for(i=0;i<=Snake.size();i++){
                            if(sx==Snake[i].GetX()&&sy==Snake[i].GetY()){checkfor=1;break;}
                        }
                        if(checkfor==1){checkfor=0;continue;}
                        check=1;
                    }
                    Ghst.Appear(sx,sy,GameTime);//鬼出現
                    Nt.GhostAppear();
            }
            if(GhostOn==1){//鬼追蛇
                Ghst.GhostMove(x,y);
            }
            if(GhostOn==1&&GameTime-Ghst.GetApT()>=25){//鬼在場面上且經過了25秒 消失
                GhostOn=0;
                Ghst.GhostBye();
            }
            if(((int)x==Ghst.GetX())&&(int)y==(Ghst.GetY())){//撞鬼
                GhostOn=0;
                Ghst.GhostBye();
                Score=Score/2;
                Nt.GhostBump();
            }
            if(Mny.GetX()==Ghst.GetX()&&Mny.GetY()==Ghst.GetY()){//鬼吃錢
                Mny.Change(-5,-5);
                int mx,my,check,i,j,checkfor;
                check=0;
                checkfor=0;
                while(check==0){//檢查物件位置有無重複
                    mx=(rand()+GameTime)%width;
                    my=rand()%(height-2)+2;
                    if(mx==Psn.GetX()&&my==Psn.GetY()){continue;}
                    if(mx==Spr.GetX()&&my==Spr.GetY()){continue;}
                    if(mx==Ghst.GetX()&&my==Ghst.GetY()){continue;}
                    if(WallMap[mx][my]==1){continue;}
                    for(i=0;i<=Snake.size();i++){
                        if(mx==Snake[i].GetX()&&my==Snake[i].GetY()){checkfor=1;break;}
                    }
                    if(checkfor==1){checkfor=0;continue;}
                    check=1;
                }
                Mny.Change(mx,my);//改金幣位置
                Score-=3000;
                Nt.GhostEatMoney();
            }
            if(GhostOn==1){
                if(Ghst.GetX()==Psn.GetX()&&Ghst.GetY()==Psn.GetY()){//鬼吃毒
                    GhostOn=0;
                    Ghst.GhostBye();
                    Score+=3000;
                    Nt.GhostEliminate();
                }
                if(WallMap[(Ghst.GetX())][(Ghst.GetY())]==1){//鬼撞牆
                    Ghst.SetCheck();
                }
                if(WallMap[(Ghst.GetX())][(Ghst.GetY())]>1){//鬼進入傳送門
                    int Number=WallMap[(Ghst.GetX())][(Ghst.GetY())];
                    int i,j,ax,ay;
                    for(i=0;i<width;i++){
                        for(j=0;j<height;j++){
                            if(WallMap[i][j]==Number&&i!=Ghst.GetX()&&j!=Ghst.GetY()){ax=i;ay=j;}
                        }
                    }
                    Ghst.SetPosition(ax+u,ay+v);
                }
            }
            if(((bx-x)<=-1)||(bx>x)||((by-y)<=-1)||(by>y)){//保持蛇長度
                Body a(x,y);
                Snake.insert(Snake.begin(),a);
                if(Snake.size()>MaxBody){
                    Snake[MaxBody].Clean();
                    if(WallMap[Snake[MaxBody].GetX()][Snake[MaxBody].GetY()]==1){//如果最後一節是牆壁 補畫
                        Snake[MaxBody].GiveWall();
                    }
                    Snake[1].Change();
                    Snake.erase(Snake.end());
                }
            }
            if(Life==0){//沒命死亡
                GameOver(Score);
            }
        }
        switch (c) {//控制按鍵
            case KEY_LEFT:
                if(Snake[0].GetY()!=Snake[1].GetY()){u=-1; v=0;break;}//防止連按
                break;
            case KEY_RIGHT:
                if(Snake[0].GetY()!=Snake[1].GetY()){u=1; v=0;break;}
                break;
            case KEY_UP:
                if(Snake[0].GetX()!=Snake[1].GetX()){u=0; v=-1;break;}
                break;
            case KEY_DOWN:
                if(Snake[0].GetX()!=Snake[1].GetX()){u=0; v=1;break;}
                break;
            case 27://esc
                GameOver(Score);
            case 'p':
                Pause(width,time(NULL));
            case 'b':
                if(Score>10000){
                    Life++;
                    Score-=10000;
                    Nt.Buy();
                }
                else{
                    Nt.NeedMore();
                }
            default: ;
        }
    }
    endwin();//結束遊戲
    return 0;
}

