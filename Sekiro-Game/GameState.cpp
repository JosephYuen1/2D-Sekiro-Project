#include "GameState.h"

void GameState::initKeyBinds()
{
	keyBinds.emplace("MOVE_LEFT", supportedKeys->at("A"));
	keyBinds.emplace("MOVE_RIGHT", supportedKeys->at("D"));
	keyBinds.emplace("MOVE_UP", supportedKeys->at("W"));
	keyBinds.emplace("MOVE_DOWN", supportedKeys->at("S"));
	keyBinds.emplace("ESCAPE", supportedKeys->at("Escape"));
}

void GameState::initTextures()
{
	sf::Texture temp;
	temp.loadFromFile("Resources/Sprites/astronaut_sprite.gif");
	texture["PLAYER_IDLE"] = temp;

	if (!texture["PLAYER_IDLE"].loadFromFile("Resources/Sprites/Astronaut_Sprite.gif")) {
		throw "ERROR LOADING PLAYER IDLE\n";
	}
}

void GameState::initPlayers()
{
	player = new Player(0,0,texture["PLAYER_IDLE"]);
}

GameState::GameState(sf::RenderWindow* window ,std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : 
	State(window, supportedKeys, states)
{
	initKeyBinds();
	initTextures();
	initPlayers();
}

GameState::~GameState()
{
	std::cout << "Ending game state! " << "\n"; 
	delete player;
}

void GameState::updateInput(const float& deltaTime)
{
	//checkForQuit();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_LEFT")))) {
		player->move(deltaTime, -1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_RIGHT")))) {
		player->move(deltaTime, 1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_UP")))) {
		player->move(deltaTime, 0.0f, -1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("MOVE_DOWN")))) {
		player->move(deltaTime, 0.0f, 1.0f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keyBinds.at("ESCAPE")))) {
		endState();
	}
}

void GameState::update(const float& deltaTime)
{
	updateMousePosition();
	updateInput(deltaTime);
	player->update(deltaTime);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = window;
		player->render(target);
	}
}
