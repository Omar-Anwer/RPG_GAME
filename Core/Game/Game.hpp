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

class Game {

private:
	// Constructor
	Game();

	// Delete copy constructor and assignment operator
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	// Methods
	void initWindow(void);
	void initStates(void);
	void initKeys(void);

	void endApplication();


	void handleEvents(void);
	void update(void);
	void render(void);

	// Members
	sf::RenderWindow* m_window;
	sf::Event m_event{};
	sf::Clock m_dtClock;

	std::stack<State*> states;
	//std::map<char*, int> supportedKeys;

	float m_dt;

	// Compile-time constants
	static constexpr unsigned WINDOW_WIDTH = 800;
	static constexpr unsigned WINDOW_HEIGHT = 600;
	static constexpr const char* WINDOW_TITLE = "Game Title";

public:
	// Destructor
	virtual ~Game();

	// Singleton accessor
	static Game& getInstance();

	// Methods
	void run(void);
};

#endif // GAME_HPP
