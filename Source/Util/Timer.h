#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <chrono>

using Time_Point = std::chrono::high_resolution_clock::time_point;

class Timer
{
    public:
        Timer();

        double getTime();

    private:
        Time_Point getTimeNow();

        Time_Point m_startTime;
};

#endif // TIMER_H_INCLUDED
