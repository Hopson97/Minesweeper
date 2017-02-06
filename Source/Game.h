#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stack>
#include <memory>

#include "States/State.h"

class Game
{
    public:
        Game();

        void runLoop();

        void pushState(std::unique_ptr<State::S_Base> state);
        void popState();

        void changeState(std::unique_ptr<State::S_Base> state);

    private:
        std::stack<std::unique_ptr<State::S_Base>> m_states;

        bool m_isRunning;
};

#endif // GAME_H_INCLUDED
