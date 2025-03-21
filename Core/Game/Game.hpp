#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>

#include <cstdint>
#include <cstdlib>
#include <ctime>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

#include "Core\States\GameState.hpp"
#include "Core\States\MainMenuState.hpp"

class Game {

private:
	// Constructor
	Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	// Members
	std::unique_ptr<sf::RenderWindow> m_window;
	std::stack< std::unique_ptr<State>> states;
	sf::Event m_event{};
	sf::Clock m_dtClock;
	float m_dt;

	// Compile-time constants
	static constexpr unsigned int WINDOW_WIDTH = 800;
	static constexpr unsigned int WINDOW_HEIGHT = 600;
	static constexpr const char* WINDOW_TITLE = "Game Title";

	// Methods
	void initWindow(void);
	void initStates(void);
	void initKeys(void);

	void endApplication();

public:
	// Destructor
	virtual ~Game();

	// Singleton accessor
	static Game& getInstance();

	// Methods
	void run(void);
	void handleEvents(void);
	void update(void);
	void render(void);
};

#endif // GAME_HPP
