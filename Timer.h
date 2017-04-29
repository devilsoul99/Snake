#include <ctime>//F74024020
class Timer{
public:
    Timer();
    int GetTime();
private:
    time_t start;
};
