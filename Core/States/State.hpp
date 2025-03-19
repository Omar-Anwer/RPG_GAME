#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <vector>
#include <stack>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class State {
private:
    sf::RenderWindow* m_window;

    // Resources
	std::map<std::string, sf::Texture> textures;    

public:
    State();
    State(sf::RenderWindow* window);
    virtual ~State();

    virtual void endState() = 0;

    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

//class MainMenuState : public State { /* ... */ };
//class PlayingState : public State { /* ... */ };

#endif // STATE_HPP
