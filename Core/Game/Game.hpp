#ifndef GAME_H
#define GAME_H

#include <iostream>

#include <ctime>
#include <cstdint>
#include <cstdlib>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"


class Game {

private:

	sf::RenderWindow *sfWindow;
	sf::Event sfEvent;
	sf::Clock dtClock;

	float dt;

	void initWindow();
public:
	Game();
	virtual ~Game();

	// Methods
	void update(void);
	void updateDt(void);
	void updateSfmlEvents(void);
	void run(void);
	void render(void);

};


#endif // GAME_H
