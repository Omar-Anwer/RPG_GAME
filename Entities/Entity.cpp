#include "Entity.hpp"

Entity::Entity()
{
	m_shape.setSize(sf::Vector2f(50.F, 50.F));
	m_shape.setFillColor(sf::Color::White);
	m_moveSpeed = 100.0F;
}

Entity::~Entity()
{
}

void Entity::update(const float& dt)
{
}

void Entity::render(sf::RenderTarget* target)
{
	if (target) 
	{
		target->draw(m_shape);
	}
}

void Entity::move(const float& dt, const sf::Vector2f& direction)
{
	m_shape.move(direction * (m_moveSpeed * dt));
}
