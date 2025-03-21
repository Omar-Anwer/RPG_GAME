#include "MoveCommand.hpp"

MoveCommand::MoveCommand(Entity& entity, sf::Vector2f direction)
    : m_entity(entity), m_direction(direction) {}

void MoveCommand::execute(const float& dt) {
    m_entity.move(dt, m_direction);
}