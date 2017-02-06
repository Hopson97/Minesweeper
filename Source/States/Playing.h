#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "State.h"

#include "../Game/Board.h"

namespace State
{
    class Playing : public S_Base
    {
        public:
            Playing(Game& game);

            void logic() override;

        private:
            void drawBoard ();
            void getInput  ();

            Board m_board;
    };
}

#endif // PLAYING_H_INCLUDED
