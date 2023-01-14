#include "Game.h"

//Initializers
void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Sukiro SFML");
}

//Constructor/Destructor
Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete window;
}

//Functions 
void Game::updateSFMLEvents()
{
	while (window->pollEvent(sfEvent)) {

		if (sfEvent.type == sf::Event::Closed) {
			window->close();
		}
	}
}

void Game::update()
{
	updateSFMLEvents();
}

void Game::render()
{
	window->clear();

	//Render items 
	window->display();
}

void Game::run()
{
	while (window->isOpen()) {
		update();
		render();
	}
}
