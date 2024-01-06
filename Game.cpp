#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gra",sf::Style::Close|sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete window;
}



void Game::run()
{
	while (window->isOpen()) {
		this->update();
		this->render();
	}
}
void Game::updatePollEvent()
{
	sf::Event event;
	while (this->window->pollEvent(event)) {
		if (event.Event::type == sf::Event::Closed)
			this->window->close();
		if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::update()
{
	this->updatePollEvent();
}

void Game::render()
{
	this->window->clear();


	this->window->display();
}
