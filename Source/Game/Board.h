#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include <string>

#include "Node.h"
#include "../Util/Vector2.h"

class Board
{
    constexpr static int HEIGHT     = 15;
    constexpr static int WIDTH      = 15;
    constexpr static int NUM_BOMBS  = 10;

    public:
        Board();

        void draw();

    private:
        std::vector<Vector2> getBombLocations();

        void temp_setChar(const Vector2& location, char c);

        Node& getNodeAt (const Vector2& location);

        std::vector<Node>   m_nodes;
        std::string         m_board;
};

#endif // BOARD_H_INCLUDED
