#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
}

GameState::~GameState()
{
}

void GameState::updateInput(const float& deltaTime)
{
	checkForQuit();
}

void GameState::update(const float& deltaTime)
{
	//std::cout << "Hello from gameState\n";
	/*updateInput(deltaTime);
	player.update(deltaTime);*/

	checkForQuit();
	//update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player.move(deltaTime, -1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.move(deltaTime, 1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player.move(deltaTime, 0.0f, -1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player.move(deltaTime, 0.0f, 1.0f);
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = window;
		player.render(target);
	}

}
