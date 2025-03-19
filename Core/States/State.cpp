#include "Core\States\State.hpp"

State::State()
{
}

State::State(sf::RenderWindow* window) {
	m_window = window;
}

State::~State()
{
}
