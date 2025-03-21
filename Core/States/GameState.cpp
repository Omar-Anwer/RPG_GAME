#include "GameState.hpp"
#include "Core/Input/InputHandler.hpp"
#include "Core/Commands/MoveCommand.hpp"



GameState::GameState(sf::RenderWindow* window):
	State(window)
{
	//auto& input = InputHandler::getInstance();


	//// Bind actions to movement commands
	//input.bindAction(Action::MOVE_LEFT, std::make_unique<MoveCommand>(m_player, sf::Vector2f(-1.f, 0.f)));
	//input.bindAction(Action::MOVE_RIGHT, std::make_unique<MoveCommand>(m_player, sf::Vector2f(1.f, 0.f)));
	//input.bindAction(Action::MOVE_UP, std::make_unique<MoveCommand>(m_player, sf::Vector2f(0.f, -1.f)));
	//input.bindAction(Action::MOVE_DOWN, std::make_unique<MoveCommand>(m_player, sf::Vector2f(0.f, 1.f)));
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
	auto& input = InputHandler::getInstance();

	// Check for quit
	if (input.isActive(Action::QUIT)) {
		m_isQuit = true;
	}

	// Movement handling
	sf::Vector2f movement(0.f, 0.f);
	if (input.isActive(Action::MOVE_LEFT)) {
		movement.x -= 1.f;
	}
	if (input.isActive(Action::MOVE_RIGHT)) {
		movement.x += 1.f;
	}
	if (input.isActive(Action::MOVE_UP)) {
		movement.y -= 1.f;
	}
	if (input.isActive(Action::MOVE_DOWN)) {
		movement.y += 1.f;
	}
	if (movement.x != 0.f || movement.y != 0.f) {
		m_player.move(dt, movement);
	}
	//input.handleInput(dt);  // Executes bound commands

}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) 
	{
		target = m_window;
	}
	m_player.render(target);
}
