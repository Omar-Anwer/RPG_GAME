#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "State.hpp"

class GameState : public State
{
private:
	Entity m_player;
public:
	explicit GameState(sf::RenderWindow* window);
	~GameState() override = default;

	// Methods
	void endState() override;
	void update(const float& dt) override;
	void handleInput(const float& dt) override;
	void render(sf::RenderTarget* target = nullptr) override;
};

#endif // GAME_STATE_HPP
