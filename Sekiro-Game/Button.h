#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>

#include  <SFML/System.hpp>
#include  <SFML/Graphics.hpp>
#include  <SFML/Window.hpp>
#include  <SFML/Audio.hpp>
#include  <SFML/Network.hpp>

enum button_states {
	b_idle = 0,
	b_hovered,
	b_active

};
class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape buttonShape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColour;
	sf::Color hoverColour;
	sf::Color activeColour;

public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text,
		sf::Color idleColour, sf::Color hoverColour, sf::Color activeColour);
	~Button();

	//Accessors 
	const bool isPressed();

	//Functions
	void update(const sf::Vector2f mousePosWindow);
	void render(sf::RenderTarget* target);

};

#endif