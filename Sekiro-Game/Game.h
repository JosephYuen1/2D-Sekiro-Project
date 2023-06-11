#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game {
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float deltaTime;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;

	//Initialization
	void initWindow();
	void initKeys();
	void initStates();

public:
	Game();
	virtual ~Game();

	//Functions 
	void endApplication();
	void updateDeltaTime();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};
#endif