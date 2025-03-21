#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window):
	State(window)
{
}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "Ending Game state.\n";
}

void GameState::update(const float& dt)
{
	handleInput(dt);
	m_player.update(dt);
}

void GameState::handleInput(const float& dt)
{
	checkQuit();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player.move(dt, -1.0F, 0.0F);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.move(dt, 1.0F, 0.0F);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_player.move(dt, 0.0F, -1.0F);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_player.move(dt, 0.0F, 1.0F);
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) 
	{
		target = m_window;
	}
	m_player.render(target);
}
