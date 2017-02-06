#include "Board.h"

#include <iostream>

Board::Board()
:   m_nodes(WIDTH * HEIGHT)
{
    for (int y = 0 ; y < HEIGHT ; y++)
    {
        for (int x = 0 ; x < WIDTH ; x++)
        {
            m_board.append(". ");
        }
        m_board.append("\n");
    }
}

void Board::draw()
{
    std::cout << m_board << std::endl;
}


Node& Board::getNodeAt(const Vector2& location)
{
    return m_nodes[location.y * WIDTH + location.x];
}
