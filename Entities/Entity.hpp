#pragma once

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <concepts>

//template<typename T>
//concept Drawable = requires(T t, sf::RenderTarget & target) {
//	{ t.draw(target) } -> std::same_as<void>;
//};

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
	virtual void move(const float& dt, const sf::Vector2f& direction);
};