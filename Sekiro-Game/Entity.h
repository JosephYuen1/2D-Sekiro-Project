#ifndef ENTITY_H
#define ENTITY_H

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

class Entity 
{
private:

protected:
	sf::RectangleShape shape;
	float movementSpeed;
public:
	Entity();
	virtual ~Entity();

	//Functions
	virtual void move(const float& deltaTime, const float dir_x, const float dir_y);
	virtual void update(const float& deltaTime);
	virtual void render(sf::RenderTarget* target);
};
#endif
