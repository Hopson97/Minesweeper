#include "Vector2.h"

Vector2::Vector2(int x, int y)
:   x (x)
,   y (y)
{}

bool operator==(const Vector2& v1, const Vector2& v2)
{
    return (v1.x == v2.x) && (v1.y == v2.y);
}
