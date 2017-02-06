#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include <string>

#include "Node.h"

class Vector2;

class Board
{
    constexpr static int HEIGHT     = 15;
    constexpr static int WIDTH      = 15;
    constexpr static int NUM_BOMBS  = 10;

    public:
        Board();

        void draw();

    private:
        void temp_setChar(const Vector2& location, char c);

        Node& getNodeAt (const Vector2& location);

        std::vector<Node>   m_nodes;
        std::string         m_board;
};

#endif // BOARD_H_INCLUDED
