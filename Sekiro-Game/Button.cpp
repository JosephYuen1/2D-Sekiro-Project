#include "Button.h"

Button::Button(float x, float y, float width, float height, 
	sf::Font* font, std::string text,
	sf::Color idleColour, sf::Color hoverColour, sf::Color activeColour)
{
	buttonShape.setPosition(sf::Vector2f(x, y));
	buttonShape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(buttonShape.getPosition().x / 2.0f - this->text.getGlobalBounds().width / 2.0f,
		buttonShape.getPosition().y / 2.0f -  this->text.getGlobalBounds().height / 2.0f);


	this->idleColour = idleColour;
	this->hoverColour = hoverColour;
	this->activeColour = activeColour;
}

Button::~Button()
{
}

void Button::update(const sf::Vector2f mousePos)
{
	//update the booleans for hover and pressed
	if (buttonShape.getGlobalBounds().contains(mousePos)) {

	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(buttonShape);
}
