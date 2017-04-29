//F74024020
class Poison{
public:
    Poison(int a,int b,int apt);
    void Change(int a, int b,int apt);
    void Clean();
    int GetX();
    int GetY();
    int GetAPT();
private:
    int AppearTime,cx,cy;
};
