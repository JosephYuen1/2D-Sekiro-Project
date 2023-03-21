#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
{
	this->window = window;
	this->supportedKeys = supportedKeys;
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

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		quit = true;
	}
}

