#pragma once

#include <functional>
#include <memory>
#include <unordered_map>
#include "Core/Commands/Command.hpp"
#include "SFML/Window/Keyboard.hpp"

//#define USE_COMMANDS

enum class Action {
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN,
    JUMP,
    QUIT,
    UNKNOWN
};

/////////////////////////////////////////

class InputHandler {
public:
    using CommandPtr = std::unique_ptr<Command>;
    
    using ActionMap = std::unordered_map<Action, std::vector<sf::Keyboard::Key>>;
    using CommandMap = std::unordered_map<Action, CommandPtr>;

    static InputHandler& getInstance();
    
    // Delete copy/move operations
    InputHandler(const InputHandler&) = delete;
    InputHandler& operator=(const InputHandler&) = delete;
    InputHandler(InputHandler&&) = delete;
    InputHandler& operator=(InputHandler&&) = delete;
    
    // Methods
    void loadKeyBindings(const std::string& configPath);

    void bindKey(Action action, sf::Keyboard::Key key);
    void bindAction(Action action, CommandPtr command);
    bool isActive(Action action) const;

    void handleInput(const float& dt);

private:
    InputHandler() = default;

    ActionMap m_actionMap;
    CommandMap m_commandMap;

    void loadDefaultBindings();

    sf::Keyboard::Key stringToKey(const std::string& keyStr);
    Action stringToAction(const std::string& actionStr);
};