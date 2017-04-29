#include "Timer.h"//F74024020

Timer::Timer(){
        start=time(NULL);
}
int Timer::GetTime(){
        return time(NULL)-start;
}
