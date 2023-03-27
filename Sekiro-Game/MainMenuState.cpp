#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	//if(!font.loadFromFile("Fonts/ "){
	// throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	//}
}

void MainMenuState::initKeyBinds()
{
	
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
	//initFonts();
	initKeyBinds();
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::updateInput(const float& deltaTime)
{
	checkForQuit();
	
}

void MainMenuState::update(const float& deltaTime)
{
	updateMousePosition();
	updateInput(deltaTime);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = window;
	}
	target->draw(background);
}