#include "GameState.h"

void GameState::initKeyBinds()
{
	keyBinds.emplace("MOVE_LEFT", supportedKeys->at("A"));
	keyBinds.emplace("MOVE_RIGHT", supportedKeys->at("D"));
	keyBinds.emplace("MOVE_UP", supportedKeys->at("W"));
	keyBinds.emplace("MOVE_DOWN", supportedKeys->at("S"));
}

GameState::GameState(sf::RenderWindow* window ,std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
	initKeyBinds();
}

GameState::~GameState()
{
}

void GameState::updateInput(const float& deltaTime)
{
	checkForQuit();
	//update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_LEFT")))) {
		player.move(deltaTime,-1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_RIGHT")))) {
		player.move(deltaTime, 1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_UP")))) {
		player.move(deltaTime, 0.0f, -1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_DOWN")))) {
		player.move(deltaTime, 0.0f, 1.0f);
	}
}

void GameState::update(const float& deltaTime)
{
	//std::cout << "Hello from gameState\n";
	updateInput(deltaTime);
	player.update(deltaTime);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = window;
		player.render(target);
	}

}
