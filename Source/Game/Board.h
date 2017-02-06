#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include <string>

struct Vector2
{
    int x = 0,
        y = 0;
};

struct Node
{


    enum class Type
    {
        Normal,
        Bomb
    } type;

    bool isDug;
};

class Board
{
    constexpr static int HEIGHT = 15;
    constexpr static int WIDTH  = 15;

    public:
        Board();

        void draw();

    private:
        Node& getNodeAt (const Vector2& location);

        std::vector<Node>   m_nodes;
        std::string         m_board;
};

#endif // BOARD_H_INCLUDED
