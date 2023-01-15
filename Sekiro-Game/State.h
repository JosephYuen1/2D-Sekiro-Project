#ifndef STATE_H
#define STATE_H

#include<vector>
#include "Game.h"

//Managing resources
class State
{
private:
	std::vector<sf::Texture> texture;
public:
	State();
	virtual ~State();
	
	//Overriding
	virtual void update() = 0;
	virtual void render() = 0;
};
#endif
