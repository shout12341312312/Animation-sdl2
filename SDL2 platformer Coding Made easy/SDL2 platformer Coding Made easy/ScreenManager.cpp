#include "ScreenManager.h"

ScreenManager::ScreenManager()
{
}


ScreenManager::~ScreenManager()
{
}

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

void ScreenManager::Initialize(SDL_Renderer *renderer)
{
	currentScreen = new SplashScreen();
	transition = false;

}

void ScreenManager::LoadContent(SDL_Renderer *renderer)
{
	currentScreen->LoadContent(renderer);

	fade.loadContent(renderer, "", "", 0, 0);
	fade.SetAlpha(0.0f);
}

void ScreenManager::Update(SDL_Renderer *renderer, SDL_Event &event)
{
	if (!transition)
	{
		currentScreen->Update(renderer, event);
	}
	Transition(renderer);
		
}

void ScreenManager::Draw(SDL_Renderer *renderer)
{
	currentScreen->Draw(renderer);
}

void ScreenManager::AddScreen(GameScreen *screen, SDL_Renderer *renderer)
{
	transition = true;
	newScreen = screen;
	fade.SetActive(true);
	fade.SetAlpha(0.0f);
}

void ScreenManager::Transition(SDL_Renderer *renderer)
{
	if (transition)
	{
		fade.Update();
		if (fade.getAlpha() >= 1.0f)
		{
			currentScreen->UnloadContent();
			delete currentScreen;
			currentScreen = newScreen;
			currentScreen->LoadContent(renderer);
			newScreen = NULL;
		}
		else if(fade.getAlpha() <= 0.0f)
		{
			transition = false;
			fade.SetActive(false);
		}
	}
}

float ScreenManager::GetAlpha()
{
	return fade.getAlpha();
}

void ScreenManager::UnloadContent()
{

}