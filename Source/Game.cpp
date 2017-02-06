#include "Game.h"

#include "States/Playing.h"
#include "Util/Random.h"

Game::Game()
{
    Random::init();
    pushState(std::make_unique<State::Playing>(*this));
}

void Game::runLoop()
{
    while (m_isRunning)
    {
        system("cls");//I know "system" is bad, but I cba type out the "windows" way of clearing.

        m_states.top()->logic();
    }
}


void Game::pushState(std::unique_ptr<State::S_Base> state)
{
    m_states.push(std::move(state));
}

void Game::popState()
{
    m_states.pop();
}

void Game::changeState(std::unique_ptr<State::S_Base> state)
{
    popState();
    pushState(std::move(state));
}
