#include "Entity.h"

void Entity::initVariables()
{
	sprite = NULL;
	texture = NULL;
	movementSpeed = 1.0f;
}

Entity::Entity()
{
	//shape.setSize(sf::Vector2f(50.0f, 50.0f));
	//shape.setFillColor(sf::Color::White);
	initVariables();
}

Entity::~Entity()
{
	delete sprite;
}

void Entity::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	sprite = new sf::Sprite(*this->texture);
}

void Entity::setPosition(const float x, const float y)
{
	if (sprite) {
		sprite->setPosition(x, y);
	}
}

void Entity::move(const float& deltaTime, const float dir_x, const float dir_y)
{
	//if the sprite is the right one the move it 
	if (sprite) {
		sprite->move(dir_x * movementSpeed, dir_y * movementSpeed);
	}
}

void Entity::update(const float& deltaTime) {

}

void Entity::render(sf::RenderTarget* target) {
	if (sprite) {
		target->draw(*sprite);
	}
}