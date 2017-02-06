#ifndef VECTOR2_H_INCLUDED
#define VECTOR2_H_INCLUDED


struct Vector2
{
    Vector2() = default;
    Vector2(int x, int y);

    int x = 0,
        y = 0;
};


#endif // VECTOR2_H_INCLUDED
