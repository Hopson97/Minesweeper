#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>

struct Vector2
{
    int x = 0,
        y = 0;
};

class Board
{
    public:
        struct Node
        {


            enum class Type
            {
                Normal,
                Bomb
            } type;

            bool isDug;
        };

    private:
        Node& getNodeAt (const Vector2& location);

        std::vector<Node> m_nodes;
};

#endif // BOARD_H_INCLUDED
