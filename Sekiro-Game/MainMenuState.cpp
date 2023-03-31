#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	//if(!font.loadFromFile("Fonts/ "){
	//	throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	//}
}

void MainMenuState::initKeyBinds()
{
	
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
	initFonts();
	initKeyBinds();
	b_gameState = new Button(200, 100, 150, 50, &font, "Sekiro",
		sf::Color(0, 150, 0, 200),
		sf::Color(255, 165, 150, 255),
		sf::Color(20, 20, 20, 200));

	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	delete b_gameState;
}

void MainMenuState::updateInput(const float& deltaTime)
{
	checkForQuit();
	
}

void MainMenuState::update(const float& deltaTime)
{
	updateMousePosition();
	updateInput(deltaTime);
	b_gameState->update(mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = window;
	}
	target->draw(background);
	b_gameState->render(target);
}