#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

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

class MovementComponent
{
private:
	sf::Sprite& sprite;
	float maxVelocity;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;

	//initializer functions 

public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity);
	virtual ~MovementComponent();

	//Accessors 
	const sf::Vector2f& getVelocity()const; 

	//functions 
	void move(const float x, const float y, const float &deltaTime);
	void update(const float& deltaTime);
};

#endif 