//F74024020
class Ghost{
public:
    void Appear(double a,double b,int t);
    void GhostBye();
    void SetPosition(int a,int b);
    void GhostMove(double SnakeX,double SnakeY);
    void SetCheck();
    int GetX();
    int GetY();
    int GetApT();
private:
    double GX,GY;
    int ApT,WCK;
};
