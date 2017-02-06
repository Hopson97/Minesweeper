#include "Playing.h"

namespace State
{
    Playing::Playing(Game& game)
    :   S_Base(game)
    {

    }

    void Playing::input()
    {

    }

    void Playing::update()
    {

    }

    void Playing::draw()
    {
        m_board.draw();
    }
}
