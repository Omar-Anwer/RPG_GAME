#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "Core\States\State.hpp"

class GameState : public State
{
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// Methods
	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

#endif // GAME_STATE_HPP
