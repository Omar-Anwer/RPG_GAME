#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <vector>
#include <stack>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

#include "Entities/Entity.hpp"

class State {
private:
protected:
    sf::RenderWindow* m_window;
    bool m_isQuit;

    // Resources
	std::map<std::string, sf::Texture> textures;    

public:
    State() = default;
    explicit State(sf::RenderWindow* window);
    virtual ~State() = default;

    bool getQuit() const;

    virtual void endState() = 0;
    virtual void update(const float& dt) = 0;
    virtual void handleInput(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

//class MainMenuState : public State { /* ... */ };
//class PlayingState : public State { /* ... */ };

#endif
