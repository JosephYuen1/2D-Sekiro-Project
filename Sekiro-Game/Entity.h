#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponent.h"

class Entity 
{
private:
	void initVariables();

protected:
	sf::Texture* texture;
	sf::Sprite* sprite;

	//sf::RectangleShape shape;
	MovementComponent* movementComponent;
public:
	Entity();
	virtual ~Entity();

	//component functions 
	void createSprite(sf::Texture* texture);
	void createMovementComponent(const float maxVelocity);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& deltaTime, const float dir_x, const float dir_y);
	virtual void update(const float& deltaTime);
	virtual void render(sf::RenderTarget* target);
};
#endif
