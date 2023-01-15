#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>

#include  <SFML/System.hpp>
#include  <SFML/Graphics.hpp>
#include  <SFML/Window.hpp>
#include  <SFML/Audio.hpp>
#include  <SFML/Network.hpp>

class Game {
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float deltaTime;

	//Initialization
	void initWindow();

public:
	Game();
	virtual ~Game();

	//Functions 
	void updateDeltaTime();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};
#endif