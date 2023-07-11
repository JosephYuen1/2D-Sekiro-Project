#include "Entity.h"

void Entity::initVariables()
{
	movementComponent = NULL;
}

Entity::Entity()
{
	//shape.setSize(sf::Vector2f(50.0f, 50.0f));
	//shape.setFillColor(sf::Color::White);
	initVariables();
}

Entity::~Entity()
{

}

void Entity::setTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity)
{
	movementComponent = new MovementComponent(sprite,maxVelocity);
}

void Entity::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

void Entity::move(const float& deltaTime, const float dir_x, const float dir_y)
{
	//if the sprite is the right one the move it 
	if ( movementComponent) {
		//sets velocity 
		movementComponent->move(dir_x, dir_y, deltaTime);
	}
}

void Entity::update(const float& deltaTime) {

}

void Entity::render(sf::RenderTarget* target) {
	
	target->draw(sprite);
}