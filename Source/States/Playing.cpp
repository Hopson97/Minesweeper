#include "Playing.h"

#include <iostream>
#include <cstdlib>

namespace State
{
    Playing::Playing(Game& game)
    :   S_Base(game)
    {

    }

    void Playing::logic()
    {

    }

/*
    void Playing::input()
    {
        int x = 0;
        int y = 0;
        char command = 0;

        std::cout << "What X Location do you want to access?" << std::endl;
        std::cin >> x;

        std::cout << "What Y Location do you want to access?" << std::endl;
        std::cin >> y;

        std::cout << "Do you want to [D]ig or [F]lag (E to exit)?" << std::endl;
        std::cin >> command;

        command = std::toupper(command);

        switch(command)
        {
            case 'D':
                m_board.dig({x, y});
                break;

            case 'F':
                m_board.flag({x, y});
                break;

            case 'E':
                //exit
                break;

            default:
                std::cout << "Invalid input!" << std::endl;
                break;
        }
    }

    void Playing::update()
    {
        if (m_board.bombHit())
        {

        }
    }

    void Playing::draw()
    {
        std::cout << "Results: " << std::endl;
        m_board.draw();

        if (m_board.bombHit())
        {

        }

        std::cout << "Press any key to continue" << std::endl;
        std::cin.ignore();
        std::cin.ignore();
    }
    */
}
