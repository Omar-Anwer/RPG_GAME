#include "Game.hpp"
#include <iostream>

void Game::initWindow() {
	this->sfWindow = new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Game");
}

Game::Game() {
	this->initWindow();
}

Game::~Game() {
	delete this->sfWindow;
}

void Game::update(void) {
	this->updateSfmlEvents();
}

void Game::updateDt(void) {
	// one frame time 
	this->dt = this->dtClock.restart().asSeconds();
	system("cls");
	std::cout << this->dt << "\n";
}

void Game::updateSfmlEvents(void) {

	while (this->sfWindow->pollEvent(this->sfEvent)) {
		if (sf::Event::Closed == this->sfEvent.type) {
			this->sfWindow->close();
		}
	}
}

void Game::run(void) {
	while (this->sfWindow->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}

void Game::render(void) {
	this->sfWindow->clear();
	// Render Items
	this->sfWindow->display();
}
