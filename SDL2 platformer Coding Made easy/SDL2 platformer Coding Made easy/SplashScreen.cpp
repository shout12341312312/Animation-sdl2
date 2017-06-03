#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::LoadContent(SDL_Renderer *renderer)
{
	SplashText.loadText("SplashScreen", { 255,255,255}, renderer);

	keys.push_back(SDLK_LEFT);
	keys.push_back(SDLK_RIGHT);
}

void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();
}

void SplashScreen::Draw(SDL_Renderer *renderer)
{
	SplashText.renderText(300, 300, renderer);
}

void SplashScreen::Update(SDL_Renderer *renderer, SDL_Event &event)
{
	input.Update(event);
	if (input.KeyPressed(keys))
	{
		ScreenManager::GetInstance().AddScreen(new TitleScreen, renderer);
	}
}