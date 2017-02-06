#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

class Game;

namespace State
{
    class S_Base
    {
        public:
            S_Base(Game& game);

            virtual void logic() = 0;

        protected:
            Game* m_p_game;
    };
}

#endif // STATE_H_INCLUDED
