#include "Player.h"

void Player::initVariables()
{
}

void Player::initComponents()
{
}

Player::Player(float x, float y, sf::Texture* texture)
{
	initVariables();
	initComponents();
	createSprite(texture);
	setPosition(x, y);
}

Player::~Player()
{

}