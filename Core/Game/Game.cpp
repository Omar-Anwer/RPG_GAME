#include "Game.hpp"
#include "Core/Input/InputHandler.hpp"
#include "Core/Commands/MoveCommand.hpp"

#include <iostream>
#include <memory>


// Singleton instance accessor
Game& Game::getInstance()
{
    static Game instance;
    return instance;
}

Game::Game()
{
    m_dt = 0.f;
    initWindow();
    initKeys();
    initStates();
}

Game::~Game()
{
    //delete m_window;
    while (!states.empty())
    {
        //delete states.top();
        states.pop();
    }
}

void Game::initWindow() {
    m_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        WINDOW_TITLE);
    m_window->setFramerateLimit(60);
    m_window->setVerticalSyncEnabled(false);
    //m_window->setKeyRepeatEnabled(false);
}

void Game::initKeys(void)
{
    // Initialize input bindings
    auto& input = InputHandler::getInstance();
    const std::string configPath = "../Config/keys.ini";
    input.loadKeyBindings(configPath);
}

void Game::initStates(void) 
{
    //states.push(std::make_unique<MainMenuState>(m_window.get()));
    states.push(std::make_unique<GameState>(m_window.get()));

}

void Game::endApplication() 
{
    m_window->close();
    std::cout << "endApplication\n";
}

void Game::handleEvents(void)
{
    while (m_window->pollEvent(m_event))
    {
        if (sf::Event::Closed == m_event.type)
        {
            m_window->close();
        }
    }
}

void Game::update(void)
{
    //Render items
    if (!states.empty())
    {
        states.top()->update(m_dt);
        if (states.top()->getQuit())
        {
            states.top()->endState();
            //delete states.top();
            states.pop();
        }
    }
    else 
    {
        // Application end
        endApplication();
    }
}

void Game::run(void)
{
    while (m_window->isOpen()) 
    {
        m_dt = m_dtClock.restart().asSeconds();
        handleEvents();
        update();
        render();
#ifdef _WIN32
        //system("cls");
#endif // _WIN32
        //std::cout << "Delta time: " << m_dt << "s\n";
    }
}

void Game::render(void)
{
    m_window->clear();

    //Render items
    if (!states.empty())
    {
        states.top()->render(m_window.get());
    }

    m_window->display();
}
