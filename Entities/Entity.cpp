#include "Entity.hpp"

Entity::Entity()
{
	m_shape.setFillColor(sf::Color::White);
	m_shape.setSize(sf::Vector2f(50.0F, 50.0F));
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
	target->draw(m_shape);
}

void Entity::move(const float& dt, const float& dx, const float& dy)
{
	const float offsetX = dx * (m_moveSpeed * dt);
	const float offsetY = dy * (m_moveSpeed * dt);
	m_shape.move(offsetX, offsetY);
}
