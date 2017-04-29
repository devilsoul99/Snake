//F74024020
class Body{//蛇的一節
public:
    Body(int a,int b);
    void Change();//頭變成身體
    void GiveWall();//補印牆壁
    void Clean();//清除
    int GetX();
    int GetY();
private:
    int cx,cy;
};
