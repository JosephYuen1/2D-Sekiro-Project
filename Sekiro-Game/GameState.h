#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
class GameState : public State
{
private:

public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	//Functions 
	void updateKeyBinds(const float& deltaTime);
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
};

#endif