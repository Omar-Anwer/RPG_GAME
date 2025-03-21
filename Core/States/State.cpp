#include "State.hpp"

State::State()
{
}

State::State(sf::RenderWindow* window)
{
	m_window = window;
	m_isQuit = false;
}

State::~State()
{
}

const bool& State::getQuit() const 
{
	return (this->m_isQuit);
}

void State::checkQuit() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_isQuit = true;
	}
}

void State::endState()
{
}
