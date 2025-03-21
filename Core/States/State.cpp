#include "State.hpp"


State::State(sf::RenderWindow* window)
{
	m_window = window;
	m_isQuit = false;
}

bool State::getQuit() const 
{
	return (this->m_isQuit);
}

void State::endState()
{
}
