#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
{
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->states = states;
	quit = false;
}

State::~State()
{
}

const bool & State::getQuit() const
{
	return quit;
}

void State::endState()
{
	std::cout << "Ending game state\n";
}

void State::updateMousePosition()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(*window);
	mousePosView = window-> mapPixelToCoords(sf::Mouse::getPosition());
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		quit = true;
	}
}

