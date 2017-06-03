#pragma once

#include "header.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Update(SDL_Event &event);

	bool KeyPressed(int key);
	bool KeyPressed(std::vector<int>keys);

	bool KeyReleased(int key);
	bool KeyReleased(std::vector<int>keys);

	bool KeyDown(int key);
	bool KeyDown(std::vector<int> keys);
private:

	SDL_Event event;
};

