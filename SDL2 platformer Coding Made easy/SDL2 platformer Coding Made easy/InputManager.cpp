#include "InputManager.h"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}


void InputManager::Update(SDL_Event &event)
{
	this->event = event;
}

bool InputManager::KeyPressed(int key)
{
	if (event.key.keysym.sym == key && event.key.state == SDL_PRESSED && event.key.repeat == 0)
	{
		return true;
	}
	return false;
}

bool InputManager::KeyPressed(std::vector<int>keys)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if (KeyPressed(keys[i]))
		{
			return true;
		}
	}
	return false;
}

bool InputManager::KeyReleased(int key)
{
	if (event.key.keysym.sym == key && event.key.state == SDL_RELEASED  && event.key.repeat == 0 )
	{
		return true;
	}
	return false;
}

bool InputManager::KeyReleased(std::vector<int>keys)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if(KeyReleased(keys[i]))
		{
			return true;
		}
	}
	return false;
}

bool InputManager::KeyDown(int key)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == key)
	{
		return true;
	}
	return false;
}

bool InputManager::KeyDown(std::vector<int> keys)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if (KeyDown(keys[i]))
		{
			return true;
		}
	}

	return false;
}