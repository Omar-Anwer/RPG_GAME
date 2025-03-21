#include "InputHandler.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

// Singleton Instance
InputHandler& InputHandler::getInstance() {
    static InputHandler instance;
    return instance;
}

// Convert a string key name to SFML key
sf::Keyboard::Key InputHandler::stringToKey(const std::string& keyStr) {
    static const std::unordered_map<std::string, sf::Keyboard::Key> keyMap = {
        {"A", sf::Keyboard::A}, 
        {"D", sf::Keyboard::D},
        {"W", sf::Keyboard::W},
        {"S", sf::Keyboard::S},
        {"G", sf::Keyboard::G},
        {"Space", sf::Keyboard::Space}, 
        {"Escape", sf::Keyboard::Escape}
    };
    auto it = keyMap.find(keyStr);
    return (it != keyMap.end()) ? it->second : sf::Keyboard::Unknown;
}

// Convert an action name string to enum
Action InputHandler::stringToAction(const std::string& actionStr) {
    static const std::unordered_map<std::string, Action> actionMap = {
        {"MOVE_LEFT", Action::MOVE_LEFT}, {"MOVE_RIGHT", Action::MOVE_RIGHT},
        {"MOVE_UP", Action::MOVE_UP}, {"MOVE_DOWN", Action::MOVE_DOWN},
        {"JUMP", Action::JUMP}, {"QUIT", Action::QUIT}
    };
    auto it = actionMap.find(actionStr);
    return (it != actionMap.end()) ? it->second : Action::UNKNOWN;
}

void InputHandler::loadDefaultBindings() {
    m_actionMap[Action::MOVE_LEFT] = { sf::Keyboard::A, sf::Keyboard::Left };
    m_actionMap[Action::MOVE_RIGHT] = { sf::Keyboard::D, sf::Keyboard::Right };
    m_actionMap[Action::MOVE_UP] = { sf::Keyboard::W, sf::Keyboard::Up };
    m_actionMap[Action::MOVE_DOWN] = { sf::Keyboard::S, sf::Keyboard::Down };
    m_actionMap[Action::QUIT] = { sf::Keyboard::Escape };
}

// Load bindings from INI file but DO NOT bind keys automatically
void InputHandler::loadKeyBindings(const std::string& configPath) {
    std::ifstream file(configPath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open key bindings file: " << configPath << std::endl;
        loadDefaultBindings();
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '[') continue;  // Ignore empty lines & sections

        std::istringstream ss(line);
        std::string actionStr, keyStr;
        if (std::getline(ss, actionStr, '=') && std::getline(ss, keyStr)) {
            Action action = stringToAction(actionStr);
            sf::Keyboard::Key key = stringToKey(keyStr);
            if (action != Action::UNKNOWN && key != sf::Keyboard::Unknown) {
                m_actionMap[action].push_back(key);  // Store key but don't bind action yet
            }
        }
    }
}

// Manually bind a key to an action
void InputHandler::bindKey(Action action, sf::Keyboard::Key key) {
    m_actionMap[action].push_back(key);
}

// Bind a command to an action
void InputHandler::bindAction(Action action, CommandPtr command) {
    m_commandMap[action] = std::move(command);
}

bool InputHandler::isActive(Action action) const {
    auto it = m_actionMap.find(action);
    if (it != m_actionMap.end()) {
        for (auto key : it->second) {
            if (sf::Keyboard::isKeyPressed(key)) {
                return true;
            }
        }
    }
    return false;
}

// Handle input and execute commands
void InputHandler::handleInput(const float& dt) {
    for (const auto& [action, keys] : m_actionMap) {
        for (auto key : keys) {
            if (sf::Keyboard::isKeyPressed(key) && m_commandMap.count(action)) {
                m_commandMap[action]->execute(dt);
            }
        }
    }
}
