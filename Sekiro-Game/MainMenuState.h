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

	std::map<std::string, Button*> buttons;

	//functions 
	void initFonts();
	void initKeyBinds();
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	//Functions
	void endState();
	void updateInput(const float& deltaTime);
	void updateButtons();
	void update(const float& deltaTime);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
};

#endif