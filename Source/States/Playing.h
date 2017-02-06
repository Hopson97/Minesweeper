#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "State.h"

namespace State
{
    class Playing : public S_Base
    {
        public:
            Playing(Game& game);

            void input  ();
            void update ();
            void draw   ();
    };
}

#endif // PLAYING_H_INCLUDED
