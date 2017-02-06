#include "Board.h"

#include <iostream>

#include "../Util/Random.h"
#include "../Util/Vector2.h"
Board::Board()
{
    auto bombLocations = getBombLocations();


    for (int y = 0 ; y < HEIGHT ; y++)
    {
        for (int x = 0 ; x < WIDTH ; x++)
        {
            bool bombPlaced = false;
            for (auto& loc : bombLocations)
            {
                if (loc == Vector2{x, y})
                {
                    bombPlaced = true;
                    m_board.append("# ");
                }
            }

            if (!bombPlaced)
                m_board.append(". ");
        }
        m_board.append("\n");
    }
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

std::vector<Vector2> Board::getBombLocations()
{
    std::vector<Vector2> bombLocations;

    for (int i = 0 ; i < NUM_BOMBS ; i++)
    {
        int x, y;

        x = Random::intInRange(0, WIDTH - 1);
        y = Random::intInRange(0, HEIGHT - 1);

        bombLocations.push_back({x, y});
    }

    return bombLocations;
}



Node& Board::getNodeAt(const Vector2& location)
{
    return m_nodes[location.y * WIDTH + location.x];
}
