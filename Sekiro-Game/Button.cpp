#include "Button.h"

Button::Button(float x, float y, float width, float height, 
	sf::Font* font, std::string text,
	sf::Color idleColour, sf::Color hoverColour, sf::Color pressedColour)
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
	this->pressedColour = pressedColour;
}

Button::~Button()
{
}

const bool Button::isPressed()
{
	//if the button is pressed then return true 
	if (buttonState == b_pressed) {
		return true;
	}

	return false;
}

void Button::update(const sf::Vector2f mousePos)
{
	buttonState = b_idle;
	//update the booleans for hover and pressed
	if (buttonShape.getGlobalBounds().contains(mousePos)) {
		buttonState = b_hovered;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		buttonState = b_pressed;
	}


	switch (buttonState) {

	case b_idle:
		buttonShape.setFillColor(idleColour);
			break;

	case b_hovered:
		buttonShape.setFillColor(hoverColour);
		break;

	case b_pressed:
		buttonShape.setFillColor(pressedColour);
		break;

	default:
		buttonShape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(buttonShape);
	target->draw(text);
}
