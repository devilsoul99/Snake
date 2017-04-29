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

void GameOver(int Score){//����e��
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

void Pause(int width,int pt){//�Ȱ�
    init_pair(9, COLOR_RED, COLOR_WHITE);
    attrset(COLOR_PAIR(9)|A_BOLD);
    mvprintw(1, width-13, "Paused.     ");//�Ȱ��T�� �л\�ɶ�
    int c;
    while ((time(NULL)-pt)<1||(c = getch()) != 'p'){//�]�L���j�骽����U�@��P
    }
    return;
}

void SetMap(int width,int height,int *Map,int Stage){//�]�m�a�����
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

void Description(int &Stage,int &width,int &height){//�������� �������
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
    getmaxyx(stdscr, height, width);//���o���e
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
                if(Stage>1&&time(NULL)-timecheck>=1){Stage--;clear();timecheck=time(NULL);SetMap(width,height,&ShowMap[0][0],Stage);break;}//����s��
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
    Description(Stage,width,height);//�������
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);//�C������
    attrset(COLOR_PAIR(1)|A_BOLD);
    mvaddstr(0, 0, "Arrow: Move P: Pause");
    mvaddstr(1, 0, "ESC: Quit");
    attrset(A_NORMAL);
    u = 1;v = 0; x = 3; y = 3; go_on = 1;//�C������]�m
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
    int SuperStart;//�гy��ߪ���
    int GameTime;
    int LifeCheck=0;
    int k;
    int GhostOn=0;
    std::vector<Body> Snake;
    Body Head(-2,-2);//���]�@�`(�Τ���) ���F�����insert
    Snake.push_back(Head);
    Timer clock;//�гy�C���p�ɾ�
    Money Mny(10,10);//�гy��������
    Poison Psn(-1,-1,0);//�гy�r�Ī���
    Notice Nt;//�гy�i�ܿO����
    Surprise Spr(-1,-1,0);//�гy��ߪ���
    BonusTimer BTr(width);//�гy���y�p�ɾ�
    SuperTimer SpTmr(width);//�гy�L�ĭp�ɾ�
    Ghost Ghst;//�гy�����
    int WallMap[width][height];
    SetMap(width,height,&WallMap[0][0],Stage);
    while (go_on) {//�C���i�椤
        curs_set(0);
        while ((c = getch()) == ERR) { //�S��J������
            GameTime=clock.GetTime();
            attrset(COLOR_PAIR(1)|A_BOLD);
            mvprintw(0, width-13, "Score: %d  ",Score);//�C���B�ʼƾ�  ����
            mvprintw(1, width-13, "Timer: %d   ",GameTime);//�ɶ�
            mvprintw(0, width-23, "Level: %d",Level);//�[�t��
            mvprintw(0, width-33, "Stage: %d",Stage);//���d
            mvprintw(0, width-42, "Life: %d",Life);//�R��
            if(BonusTime==1){BTr.ShowSecondsLeft(GameTime);}//���y�˼Ʈɶ�
            if(SuperTime==1){SpTmr.ShowSecondsLeft(GameTime);}//�L�ĭ˼Ʈɶ�
            if(Score>10000){mvaddstr(0, 22, "B: Buy life");}
            attrset(A_NORMAL);
            if(GameTime%30==0&&GameTime!=0&&Accelcheck==0){//�C30��[�t
                Xspeed=(int)Xspeed*0.92;
                Yspeed=(int)Yspeed*0.9;
                Accelcheck=1;
                Level++;
                Nt.Accel();
            }
            if(GameTime%30==1&&GameTime!=1&&Accelcheck==1){//����h���[�t
                Accelcheck=0;
            }
            if(Nt.Elapsed()>3&&Nt.GetPower()==1){//�i�ܿO����
                Nt.Off();
            }
            {//�D����
            bx=x;by=y;
            x += u/Xspeed;
            y += v/Yspeed;
            while (x < 0) x += width;
            while (x >= width) x -= width;
            while (y <2) y = height;
            while (y > height) y = 2;}//���ʵ���
            if(((int)x==Mny.GetX())&&(int)y==(Mny.GetY())){//�Y�����
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
                srand((unsigned)time(NULL));//�ؤl
                check=0;
                checkfor=0;
                while(check==0){//�ˬd�����m���L����
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
                Mny.Change(mx,my);//�������m
            }
            if(((int)x==Psn.GetX())&&(int)y==(Psn.GetY())){//�Y��r��
                Life--;
                Psn.Change(-1,-1,GameTime);
                Nt.EatPoi();
            }
            if(WallMap[(int)x][(int)y]==1&&SuperTime==0&&LifeCheck==0){//�D������
                Life--;
                LifeCheck=1;
                Nt.HitWall();
            }
            if(LifeCheck==1&&WallMap[(int)x][(int)y]!=1){//����h�����R
                LifeCheck=0;
            }
            if(((int)x==Spr.GetX())&&(int)y==(Spr.GetY())){//�Y�����
                srand((unsigned)time(NULL));//�ؤl
                int kind=rand()%3;
                if(kind==0){//�[��3��
                    MaxBody+=3;
                    Spr.Clean();
                    Spr.Change(-1,-1,GameTime);
                    Nt.SprLength();
                    Score+=1000;
                }
                if(kind==1){//���y�ɶ��G�Q��
                    BonusTime=1;
                    BonusStart=GameTime;
                    BTr.BonusOn(GameTime);
                    Spr.Clean();
                    Spr.Change(-1,-1,GameTime);
                    Nt.SprBonus();
                    Score+=1000;
                }
                if(kind==2){//�L�Įɶ��G�Q��
                    SuperTime=1;
                    SuperStart=GameTime;
                    SpTmr.SuperOn(GameTime);
                    Spr.Clean();
                    Spr.Change(-1,-1,GameTime);
                    Nt.SprSuper();
                    Score+=1000;
                }
            }
            if(BonusTime==1&&GameTime-BonusStart>=20){//�������y�ɶ�
                BonusTime=0;
                BTr.BonusOff();
            }
            if(SuperTime==1&&GameTime-SuperStart>=20){//�����L�Įɶ�
                SuperTime=0;
                SpTmr.SuperOff();
            }
            for(k=1;k<=Snake.size();k++){//����ۤv
                if((int)x==Snake[k].GetX()&&(int)y==Snake[k].GetY()){
                    GameOver(Score);
                }
            }
            if(WallMap[(int)x][(int)y]>1){//�i�J�ǰe��
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
            if(rand()%15==1&&Psn.GetX()<=-1){//�M�w�O�_�X�{�r��
                    int px,py,check,i,j,checkfor;
                    srand((unsigned)time(NULL));//�ؤl
                    check=0;
                    checkfor=0;
                    while(check==0){//�ˬd�����m���L����
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
            if(Psn.GetX()!=-1&&GameTime-Psn.GetAPT()>=15){//�r�Ħb�����W�B�g�L�F15�� ����
                Psn.Clean();
                Psn.Change(-1,-1,GameTime);
            }
            if(rand()%37==1&&Spr.GetX()<=-1){//�M�w�O�_�X�{���
                    int sx,sy,check,i,j,checkfor;
                    srand((unsigned)time(NULL));//�ؤl
                    check=0;
                    checkfor=0;
                    while(check==0){//�ˬd�����m���L����
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
            if(Spr.GetX()!=-1&&GameTime-Spr.GetAPT()>=10){//��ߦb�����W�B�g�L�F10�� ����
                Spr.Clean();
                Spr.Change(-1,-1,GameTime);
            }
            if(Level>=10&&rand()%17==1&&GhostOn==0){//�M�w�O�_�X�{��
                    GhostOn=1;
                    int sx,sy,check,i,j,checkfor;
                    check=0;
                    checkfor=0;
                    while(check==0){//�ˬd�����m���L����
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
                    Ghst.Appear(sx,sy,GameTime);//���X�{
                    Nt.GhostAppear();
            }
            if(GhostOn==1){//���l�D
                Ghst.GhostMove(x,y);
            }
            if(GhostOn==1&&GameTime-Ghst.GetApT()>=25){//���b�����W�B�g�L�F25�� ����
                GhostOn=0;
                Ghst.GhostBye();
            }
            if(((int)x==Ghst.GetX())&&(int)y==(Ghst.GetY())){//����
                GhostOn=0;
                Ghst.GhostBye();
                Score=Score/2;
                Nt.GhostBump();
            }
            if(Mny.GetX()==Ghst.GetX()&&Mny.GetY()==Ghst.GetY()){//���Y��
                Mny.Change(-5,-5);
                int mx,my,check,i,j,checkfor;
                check=0;
                checkfor=0;
                while(check==0){//�ˬd�����m���L����
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
                Mny.Change(mx,my);//�������m
                Score-=3000;
                Nt.GhostEatMoney();
            }
            if(GhostOn==1){
                if(Ghst.GetX()==Psn.GetX()&&Ghst.GetY()==Psn.GetY()){//���Y�r
                    GhostOn=0;
                    Ghst.GhostBye();
                    Score+=3000;
                    Nt.GhostEliminate();
                }
                if(WallMap[(Ghst.GetX())][(Ghst.GetY())]==1){//������
                    Ghst.SetCheck();
                }
                if(WallMap[(Ghst.GetX())][(Ghst.GetY())]>1){//���i�J�ǰe��
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
            if(((bx-x)<=-1)||(bx>x)||((by-y)<=-1)||(by>y)){//�O���D����
                Body a(x,y);
                Snake.insert(Snake.begin(),a);
                if(Snake.size()>MaxBody){
                    Snake[MaxBody].Clean();
                    if(WallMap[Snake[MaxBody].GetX()][Snake[MaxBody].GetY()]==1){//�p�G�̫�@�`�O��� �ɵe
                        Snake[MaxBody].GiveWall();
                    }
                    Snake[1].Change();
                    Snake.erase(Snake.end());
                }
            }
            if(Life==0){//�S�R���`
                GameOver(Score);
            }
        }
        switch (c) {//�������
            case KEY_LEFT:
                if(Snake[0].GetY()!=Snake[1].GetY()){u=-1; v=0;break;}//����s��
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
    endwin();//�����C��
    return 0;
}

