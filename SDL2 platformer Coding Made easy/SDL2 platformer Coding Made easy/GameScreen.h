#pragma once

#include "header.h"
#include "InputManager.h"

class GameScreen
{
public:
	GameScreen();
	~GameScreen();

	virtual void LoadContent(SDL_Renderer *renderer);
	virtual void UnloadContent();
	virtual void Update(SDL_Renderer *renderer, SDL_Event &event);
	virtual void Draw (SDL_Renderer *renderer);

protected:
	InputManager input;
	std::vector<int> keys;

private:

};

