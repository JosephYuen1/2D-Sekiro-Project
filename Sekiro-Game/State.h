#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <stack>
#include <map>
#include <vector>

#include  <SFML/System.hpp>
#include  <SFML/Graphics.hpp>
#include  <SFML/Window.hpp>
#include  <SFML/Audio.hpp>
#include  <SFML/Network.hpp>

//Managing resources
class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> texture;
public:
	State(sf::RenderWindow* window);
	virtual ~State();
	
	//Overriding
	virtual void endState() = 0;
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
#endif
