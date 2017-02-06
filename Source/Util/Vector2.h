#ifndef VECTOR2_H_INCLUDED
#define VECTOR2_H_INCLUDED

#include <functional>

struct Vector2
{
    Vector2() = default;
    Vector2(int x, int y);

    int x = 0,
        y = 0;
};

//To have an std::unordered_map of vector 2, we need to create a hash funcion for it

namespace std
{
    template<>
    struct hash<Vector2>
    {
        size_t operator() (const Vector2& vect)
        {
            auto x = std::hash<int>{}(vect.x);
            auto y = std::hash<int>{}(vect.y);
            return std::hash<int>{}(x ^ y << 2);
        }
    };
}


#endif // VECTOR2_H_INCLUDED
