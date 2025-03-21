#pragma once
#include "Command.hpp"
#include "Entities/Entity.hpp"

class MoveCommand : public Command {
public:
    MoveCommand(Entity& entity, sf::Vector2f direction);
    void execute(const float& dt) override;

private:
    Entity& m_entity;
    sf::Vector2f m_direction;
};