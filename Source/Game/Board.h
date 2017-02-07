#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include <string>

#include "Node.h"
#include "../Util/Vector2.h"

class Board
{/*
    constexpr static int HEIGHT     = 10;
    constexpr static int WIDTH      = 10;
    constexpr static int NUM_BOMBS  = 30;
*/
    struct Board_Info
    {
        int width;
        int height;
        int numBombs;

        Board_Info(int width, int height, int numBombs)
        :   width       (width)
        ,   height      (height)
        ,   numBombs    (numBombs){}
    };

    public:
        Board(int width, int height, int numBombs);

        void draw();

        bool bombHit    () const;

        void dig        (const Vector2& location);
        void flag       (const Vector2& location);

        const Board_Info& getInfo() const;

        bool isCompleted();

        int getFlagsRemaining();

        void revealBombs();

    private:
        void floodDugSpots(const Vector2& location);
        int getNodeBombNeighbours(const Vector2& location);

        void getBombLocations();

        bool bombIsAt(const Vector2& location);

        void setCharAt(const Vector2& location, char c);
        Node& getNodeAt (const Vector2& location);

        std::vector<Node>   m_nodes;
        std::string         m_board;

        std::vector<Vector2> m_bombLocations;

        bool m_isBombHit = false;

        Board_Info m_boardInfo;

        int m_bombsFound = 0;
        int m_numFlags = 0;
};

#endif // BOARD_H_INCLUDED
