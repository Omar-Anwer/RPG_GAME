#pragma once

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class Entity
{
private:
protected:
	sf::RectangleShape m_shape;
	float m_moveSpeed;
public:
	Entity();
	virtual ~Entity();

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target = nullptr);

	virtual void move(const float& dt, const float& dx, const float& dy);
};