#include "Game.hpp"
#include <iostream>

Game::Game() :
    m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE)
{
    m_window.setFramerateLimit(120);
    m_window.setVerticalSyncEnabled(false);
   // m_window.setKeyRepeatEnabled(false);
}

void Game::update() {
    // Update game state here
}

void Game::handleEvents() {
    while (m_window.pollEvent(m_event)) {
        if (sf::Event::Closed == m_event.type)
            m_window.close();
    }
}

void Game::run(void) {
    while (m_window.isOpen()) {
        m_dt = m_dtClock.restart();
        handleEvents();
        update();
        render();
#ifdef _WIN32
        system("cls");
#endif // _WIN32
        std::cout << "Delta time: " << m_dt.asSeconds() << "s\n";
    }
}

void Game::render(void) {
    m_window.clear();
    // Draw game objects here
    m_window.display();
}
