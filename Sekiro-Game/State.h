#ifndef STATE_H
#define STATE_H

#include "Entity.h"

//Managing resources
class State
{
private:

protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> texture;
	bool quit;
public:
	State(sf::RenderWindow* window);
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
