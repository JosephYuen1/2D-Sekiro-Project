#ifndef STATE_H
#define STATE_H

#include "Entity.h"

//Managing resources
class State
{
private:

protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keyBinds;
	bool quit;

	//resources
	std::vector<sf::Texture> texture;

	//functions 
	virtual void initKeyBinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();
	const bool& getQuit() const;
	
	//Overriding
	virtual void endState();
	virtual void updateInput(const float& deltaTime) = 0;
	virtual void checkForQuit();
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
#endif
