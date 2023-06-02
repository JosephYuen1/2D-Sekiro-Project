#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")){
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeyBinds()
{
	
}

void MainMenuState::initButtons()
{
	buttons["GAME_STATE"] = new Button(200, 100, 150, 50, &font, "New Game",
		sf::Color(0, 150, 0, 200),
		sf::Color(255, 165, 150, 255),
		sf::Color(20, 20, 20, 200));

	buttons["EXIT_STATE"] = new Button(200, 300, 150, 50, &font, "Quit",
		sf::Color(0, 150, 0, 200),
		sf::Color(255, 165, 150, 255),
		sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) :
	State(window, supportedKeys, states )
{
	initFonts();
	initKeyBinds();
	initButtons();

	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	auto it = buttons.begin();
	for (it = buttons.begin(); it != buttons.end(); it++) {
		delete it->second;
	}
}
void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState!" << "\n";

}
void MainMenuState::updateInput(const float& deltaTime)
{
	checkForQuit();
	
}

void MainMenuState::updateButtons()
{
	//updates all the buttons in the state
	for (auto &it : buttons) {	
		it.second->update(mousePosView);
	}

	if (buttons["GAME_STATE"]->isPressed()) {
		states->push(new MainMenuState(window, supportedKeys, states));
	}

	//quit the game
	if (buttons["EXIT_STATE"]->isPressed()) {
		quit = true;
	}
}

void MainMenuState::update(const float& deltaTime)
{
	updateMousePosition();
	updateInput(deltaTime);
	updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : buttons) {
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = window;
	}
	target->draw(background);
	renderButtons(target);
}