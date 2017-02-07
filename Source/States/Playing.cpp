#include "Playing.h"

#include <iostream>
#include <cstdlib>

#ifdef __WIN32
#include <windows.h>
#endif // __WIN32

namespace State
{
    Playing::Playing(Game& game)
    :   S_Base(game)
    ,   m_board (8, 8, 15)
    {
        //m_board.revealBombs();
    }

    void Playing::logic()
    {
        if (m_board.bombHit())
        {
            #ifdef __WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            #endif // __WIN32

            std::cout << "Game over" << std::endl << std::endl;

            #ifdef __WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                        FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
            #endif // __WIN32

            drawBoard();

            exit(0);
        }

        drawBoard();
        getInput();
    }

    void Playing::drawBoard()
    {
        std::cout << "Number of flags left: " << m_board.getFlagsRemaining() << std::endl << std::endl;
        m_board.draw();
    }

    void Playing::getInput()
    {
        int x = 0;
        int y = 0;
        char command{};

        bool validInput = false;

        while(!validInput)
        {
            std::cout << "What X Location do you want to access?" << std::endl;
            std::cin >> x;

            if (x > m_board.getInfo().width - 1)
            {
                std::cout << "Invalid input! Please enter a number between 0 and " << m_board.getInfo().width - 1 << std::endl;
                continue;
            }

            std::cout << "What Y Location do you want to access?" << std::endl;
            std::cin >> y;

            if (y > m_board.getInfo().height - 1)
            {
                std::cout << "Invalid input! Please enter a number between 0 and " << m_board.getInfo().height - 1 << std::endl;
                continue;
            }

            std::cout << "Do you want to [D]ig or [F]lag (E to exit)?" << std::endl;
            std::cin >> command;

            command = std::toupper(command);

            switch(command)
            {
                case 'D':
                    m_board.dig({x, y});
                    validInput = true;
                    break;

                case 'F':
                    m_board.flag({x, y});
                    validInput = true;
                    break;

                case 'E':
                    exit(0);
                    break;

                default:
                    std::cout << "Invalid input!" << std::endl;
                    break;
            }
        }
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
