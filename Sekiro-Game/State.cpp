#include "State.h"

State::State(sf::RenderWindow* window)
{
	this->window = window;
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

