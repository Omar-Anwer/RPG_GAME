#pragma once

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(const float& dt) = 0;
};