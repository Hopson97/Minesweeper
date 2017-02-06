#include "Board.h"

#include <iostream>

#include "../Util/Random.h"
#include "../Util/Vector2.h"
Board::Board()
{
    m_bombLocations.reserve(WIDTH * HEIGHT);

    getBombLocations();

    for (int y = 0 ; y < HEIGHT ; y++)
    {
        for (int x = 0 ; x < WIDTH ; x++)
        {
            bool bombPlaced = false;
            for (auto& loc : m_bombLocations)
            {
                if (loc == Vector2{x, y})
                {
                    bombPlaced = true;
                    m_nodes.emplace_back(Node::Type::Bomb);
                }
            }

            if (!bombPlaced)
            {

                m_nodes.emplace_back(Node::Type::Normal);
            }

            m_board.append(". ");
        }
        m_board.append("\n");
    }
}

bool Board::bombHit() const
{
    return m_isBombHit;
}

void Board::dig(const Vector2& location)
{
    auto& node = getNodeAt(location);
    if (!node.isDug)
    {
        node.isDug = true;
        if (node.type == Node::Type::Bomb)
        {
            setCharAt(location, 'B');
            m_isBombHit = true;
        }
        else
        {
            setCharAt(location, 'D');
        }
    }
}

void Board::flag(const Vector2& location)
{
    auto& node = getNodeAt(location);
    if (!node.isDug)
    {
        getNodeAt(location).hasFlag = true;
        setCharAt(location, 'F');
    }
}

int Board::getWidth() const
{
    return WIDTH;
}

int Board::getHeight() const
{
    return HEIGHT;
}


void Board::draw()
{
    std::cout << m_board << std::endl;
}

void Board::getBombLocations()
{
    m_bombLocations.clear();

    for (int i = 0 ; i < NUM_BOMBS ; i++)
    {
        int x, y;

        x = Random::intInRange(0, WIDTH - 1);
        y = Random::intInRange(0, HEIGHT - 1);

        m_bombLocations.push_back({x, y});
    }
}

void Board::setCharAt(const Vector2& location, char c)
{
    int x = location.x;
    int y = location.y;

    m_board[(y * WIDTH + x) * 2 + y] = c;
}

Node& Board::getNodeAt(const Vector2& location)
{
    return m_nodes[location.y * WIDTH + location.x];
}
