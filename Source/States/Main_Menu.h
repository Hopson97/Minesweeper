#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED

#include "State.h"

namespace State
{
    class Main_Menu : public S_Base
    {
        public:
            Main_Menu(Game& game);

            void input  ();
            void update ();
            void draw   ();
    };
}

#endif // MAIN_MENU_H_INCLUDED
