#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"

class MainMenuState : public State
{
private:
	//Variables
	sf::RectangleShape background;
	sf::Font font;

	//functions 
	void initFonts();
	void initKeyBinds();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();

	//Functions 
	void updateInput(const float& deltaTime);
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
};

#endif