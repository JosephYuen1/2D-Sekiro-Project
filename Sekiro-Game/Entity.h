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
	void initVariables();

protected:
	sf::Texture* texture;
	sf::Sprite* sprite;

	//sf::RectangleShape shape;
	float movementSpeed;
public:
	Entity();
	virtual ~Entity();

	//component functions 
	void createSprite(sf::Texture* texture);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& deltaTime, const float dir_x, const float dir_y);
	virtual void update(const float& deltaTime);
	virtual void render(sf::RenderTarget* target);
};
#endif
