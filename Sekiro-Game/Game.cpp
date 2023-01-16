#include "Game.h"

//Initializers
void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Sukiro SFML");
}

void Game::initStates()
{
	states.push(new GameState(window));
}

//Constructor/Destructor
Game::Game()
{
	initWindow();
	initStates();
}

Game::~Game()
{
	delete window;
	while (!states.empty()) {
		delete states.top();
		states.pop();		
	}
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

void Game::endApplication()
{
	std::cout << "Ending application\n";
}

void Game::updateDeltaTime()
{
	//update and render one frame
	deltaTime = dtClock.getElapsedTime().asSeconds();

}


void Game::update()
{
	updateSFMLEvents();
	if (!states.empty()) {
		states.top()->update(deltaTime);

		if (states.top()->getQuit()) {
			states.top()->endState();
			delete states.top();
			states.pop();
		}
	}

	//Ending the application
	else {
		endApplication();
		window->close();	
	}
}

void Game::render()
{
	window->clear();

	//Render items 
	if (!states.empty()) {
		states.top()->render();
	}
	window->display();
}

void Game::run()
{
	while (window->isOpen()) {
		updateDeltaTime();
		update();
		render();
	}
}
