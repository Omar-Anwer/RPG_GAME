#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include <ctime>
#include <cstdint>
#include <cstdlib>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"


class Game {

private:

	// Methods
	void handleEvents();
	void update(void);
	void render(void);

	// Members
	sf::RenderWindow m_window;
	sf::Event m_event{};
	sf::Clock m_dtClock;
	sf::Time m_dt;

	// Compile-time constants
	static constexpr uint16_t WINDOW_WIDTH = 800;
	static constexpr uint16_t WINDOW_HEIGHT = 600;
	static constexpr const char* WINDOW_TITLE = "Game Title";

public:
	Game();
	~Game() = default;

	// Copy Prevention
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	// Methods
	void run(void);

};

#endif // GAME_H
