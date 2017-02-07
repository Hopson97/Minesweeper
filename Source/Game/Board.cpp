#include "Board.h"

#include <iostream>

#include "../Util/Random.h"
#include "../Util/Vector2.h"


namespace
{
    const char UNDUG = ',';
    const char DUG   = '~';
    const char BOMB  = 'B';
    const char FLAG  = 'F';
}

Board::Board(int width, int height, int numBombs)
:   m_boardInfo (width, height, numBombs)
{
    getBombLocations();

    for (int y = 0 ; y < m_boardInfo.height ; y++)
    {
        for (int x = 0 ; x < m_boardInfo.width ; x++)
        {
            bool bombPlaced = false;
            for (auto& loc : m_bombLocations)
            {
                if (loc == Vector2{x, y})
                {
                    bombPlaced = true;
                    m_nodes.emplace_back(Node::Type::Bomb);
                    //m_board.append("# ");
                }
            }

            if (!bombPlaced)
            {
                m_nodes.emplace_back(Node::Type::Normal);
                //m_board.append(". ");
            }
            m_board.append(", ");
        }
        m_board.append("\n");
    }
}

void Board::revealBombs()
{
    for (auto& loc : m_bombLocations)
    {
        setCharAt(loc, 'B');
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
        if (node.type == Node::Type::Bomb)
        {
            setCharAt(location, BOMB);
            m_isBombHit = true;
        }
        else
        {

            //setCharAt(location, 'D');
            floodDugSpots(location);
        }
    }
}

void Board::flag(const Vector2& location)
{
    if (m_numFlags == m_boardInfo.numBombs)
        return;

    auto& node = getNodeAt(location);

    if (node.hasFlag)
    {
        node.hasFlag = false;
        setCharAt(location, UNDUG);
        m_numFlags--;
        if (node.type == Node::Type::Bomb)
        {
            m_bombsFound--;
        }
        return;
    }

    if (!node.isDug)
    {
        m_numFlags++;
        node.hasFlag = true;
        setCharAt(location, FLAG);
    }
    if (node.type == Node::Type::Bomb)
    {
        m_bombsFound++;
    }
}

const Board::Board_Info& Board::getInfo() const
{
    return m_boardInfo;
}

bool Board::isCompleted()
{
    return m_bombsFound == m_boardInfo.numBombs;
}

int Board::getFlagsRemaining()
{
    return m_boardInfo.numBombs - m_numFlags;
}


void Board::draw()
{
    for (int x = 0 ; x < m_boardInfo.width ; x++)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl << std::endl;



    std::cout << m_board << std::endl;
}

void Board::floodDugSpots(const Vector2& nodeLocation)
{
    int x = nodeLocation.x;
    int y = nodeLocation.y;

    if (x < 0 || x > m_boardInfo.width - 1)
    {
        return;
    }
    if (y < 0 || y > m_boardInfo.height - 1)
    {
        return;
    }

    Node& node = getNodeAt(nodeLocation);
    if (node.type == Node::Type::Bomb)
    {
        return;
    }

    bool adj = false;
    int count = getNodeBombNeighbours(nodeLocation);
    if (count > 0)
    {
        adj = true;
        setCharAt(nodeLocation, '0' + count);
    }

    if (node.isDug)
    {
        return;
    }
    if (node.hasFlag)
    {
        return;
    }

    node.isDug = true;
    if(!adj)
        setCharAt(nodeLocation, DUG);
    else
    {
        return;
    }

    if (!getNodeAt({x - 1, y}).isDug)
    {
        floodDugSpots({x - 1, y});
    }

    if (!getNodeAt({x, y - 1}).isDug)
    {
        floodDugSpots({x, y - 1});
    }

    if (!getNodeAt({x + 1, y}).isDug)
    {
        floodDugSpots({x + 1, y});
    }

    if (!getNodeAt({x, y + 1}).isDug)
    {
        floodDugSpots({x, y + 1});
    }

}

int Board::getNodeBombNeighbours(const Vector2& location)
{
    int count = 0;

    for (int x = -1 ; x <= 1 ; x++)
    {
        if (location.x + x < 0 ||
            location.x + x > m_boardInfo.width - 1)
            continue;

        for (int y = -1 ; y <= 1 ; y++)
        {
            if (location.y + y < 0 ||
                location.y + y > m_boardInfo.height - 1)
                continue;

            if (getNodeAt({location.x + x, location.y + y}).type == Node::Type::Bomb)
            {
                count++;
            }
        }
    }

    return count;
}



void Board::getBombLocations()
{
    m_bombLocations.clear();

    for (int i = 0 ; i <= m_boardInfo.numBombs ; i++)
    {
        int x, y;
        while(bombIsAt({x, y}))
        {
            x = Random::intInRange(0, m_boardInfo.width - 1);
            y = Random::intInRange(0, m_boardInfo.height - 1);
        }

        m_bombLocations.push_back({x, y});
    }
    m_bombLocations.erase(m_bombLocations.begin());
}

bool Board::bombIsAt(const Vector2& location)
{
    for (auto& bombLocation : m_bombLocations)
    {
        if(bombLocation == location)
            return true;
    }
    return false;
}


void Board::setCharAt(const Vector2& location, char c)
{
    int x = location.x;
    int y = location.y;

    m_board[(y * m_boardInfo.width + x) * 2 + y] = c;
}

Node& Board::getNodeAt(const Vector2& location)
{
    return m_nodes[location.y * m_boardInfo.width + location.x];
}
