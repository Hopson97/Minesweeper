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

bool operator == (const Vector2& v1, const Vector2& v2);

#endif // VECTOR2_H_INCLUDED
