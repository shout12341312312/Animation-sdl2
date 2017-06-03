#include "TitleScreen.h"

TitleScreen::TitleScreen()
{

}

TitleScreen::~TitleScreen()
{

}

void TitleScreen::LoadContent(SDL_Renderer *renderer)
{
	TitleText.loadText("TitleScreen", { 255,255,255 }, renderer);

	keys.push_back(SDLK_RIGHT);
	keys.push_back(SDLK_LEFT);
}

void TitleScreen::UnloadContent()
{
	GameScreen::UnloadContent();
}

void TitleScreen::Draw(SDL_Renderer *renderer)
{
	TitleText.renderText(300, 300, renderer);
}

void TitleScreen::Update(SDL_Renderer *renderer, SDL_Event &event)
{
	input.Update(event);
	if (input.KeyPressed(keys))
	{
		ScreenManager::GetInstance().AddScreen(new SplashScreen, renderer);
	}
}