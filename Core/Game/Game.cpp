#include "Game.hpp"
#include <iostream>

// Singleton instance accessor
Game& Game::getInstance() {
    static Game instance;
    return instance;
}

Game::Game() {
    this->initWindow();
    this->initStates();
}

Game::~Game() {
    delete m_window;
    while (!states.empty()){
        delete states.top();
        states.pop();
    }
}

void Game::initWindow(void) {
    m_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    m_window->setFramerateLimit(120);
    m_window->setVerticalSyncEnabled(false);
    // m_window.setKeyRepeatEnabled(false);
}

void Game::initStates(void) {
    states.push(new GameState(m_window));
}

void Game::handleEvents(void) {
    while (m_window->pollEvent(m_event)) {
        if (sf::Event::Closed == m_event.type) {
            m_window->close();
        }
    }
}

void Game::update(void) {
    handleEvents();
    //Render items
    if (!this->states.empty()) {
        this->states.top()->update(m_dt);
    }
}

void Game::run(void) {
    while (m_window->isOpen()) {
        m_dt = m_dtClock.restart().asSeconds();
        update();
        render();
#ifdef _WIN32
        system("cls");
#endif // _WIN32
        std::cout << "Delta time: " << m_dt << "s\n";
    }
}

void Game::render(void) {
    m_window->clear();

    //Render items
    if (!states.empty()) {
        states.top()->render(m_window);
    }
    m_window->display();
}
