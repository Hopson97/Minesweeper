#include "Board.h"

#include <iostream>

#include "../Util/Vector2.h"

Board::Board()
{
    for (int y = 0 ; y < HEIGHT ; y++)
    {
        for (int x = 0 ; x < WIDTH ; x++)
        {
            m_board.append(". ");
        }
        m_board.append("\n");
    }

    temp_setChar({2, 3}, '#');
}

void Board::temp_setChar(const Vector2& location, char c)
{
    int x = location.x;
    int y = location.y;

    m_board[(y * WIDTH + x) * 2 + y] = c;
}


void Board::draw()
{
    std::cout << m_board << std::endl;
}


Node& Board::getNodeAt(const Vector2& location)
{
    return m_nodes[location.y * WIDTH + location.x];
}
