#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
}

GameState::~GameState()
{
}

void GameState::updateKeyBinds(const float& deltaTime)
{
	checkForQuit();
}

void GameState::update(const float& deltaTime)
{
	//std::cout << "Hello from gameState\n";
	updateKeyBinds(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		std::cout << "A \n";
	}
}

void GameState::render(sf::RenderTarget* target)
{
}
