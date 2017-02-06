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

        bool bombHit    () const;

        void dig        (const Vector2& location);
        void flag       (const Vector2& location);

        int getWidth    ()  const;
        int getHeight   ()  const;


    private:
        void getBombLocations();

        void setCharAt(const Vector2& location, char c);
        Node& getNodeAt (const Vector2& location);

        std::vector<Node>   m_nodes;
        std::string         m_board;

        std::vector<Vector2> m_bombLocations;

        bool m_isBombHit = false;
};

#endif // BOARD_H_INCLUDED
