#include "Game.h"

#include "States/Playing.h"

Game::Game()
{
    pushState(std::make_unique<State::Playing>(*this));
}

void Game::runLoop()
{
    while (m_isRunning)
    {
        m_states.top()->input   ();
        m_states.top()->update  ();
        m_states.top()->draw    ();
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
