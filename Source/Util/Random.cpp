#include "Random.h"

#include <random>
#include <ctime>

namespace
{
    std::minstd_rand randDevide;


    void init()
    {
        randDevide.seed(time(nullptr));
    }
}

namespace Random
{
    int intInRange(int low, int high)
    {
        std::uniform_int_distribution<int> dist (low, high);

        return dist(randDevide);
    }
}
