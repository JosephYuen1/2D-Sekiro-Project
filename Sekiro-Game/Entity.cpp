#include "Entity.h"

Entity::Entity()
{
	shape.setSize(sf::Vector2f(50.0f, 50.0f));
	shape.setFillColor(sf::Color::White);
	movementSpeed = 1.0f;
}

Entity::~Entity()
{
}

void Entity::move(const float& deltaTime, const float dir_x, const float dir_y)
{
	shape.move(dir_x * movementSpeed,  dir_y * movementSpeed );
}

void Entity::update(const float& deltaTime) {

}

void Entity::render(sf::RenderTarget* target) {
	target->draw(shape);
}