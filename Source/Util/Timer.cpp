#include "Timer.h"

#include <cmath>

Timer::Timer()
{
    m_startTime = getTimeNow();
}

double Timer::getTime()
{
    auto endTime = getTimeNow();

    return std::chrono::duration_cast<std::chrono::microseconds>(endTime - m_startTime).count() * pow(10, 6);
}

Time_Point Timer::getTimeNow()
{
    return std::chrono::high_resolution_clock::now();
}
