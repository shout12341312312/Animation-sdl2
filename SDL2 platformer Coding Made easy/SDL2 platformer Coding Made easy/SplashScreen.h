#pragma once
#include "GameScreen.h"
#include "ScreenManager.h"
#include "TitleScreen.h"
#include "Texture.h"

class SplashScreen : public GameScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void LoadContent(SDL_Renderer *renderer);
	void UnloadContent();
	void Update(SDL_Renderer *renderer, SDL_Event &event);
	void Draw(SDL_Renderer *renderer);

private:

	Texture SplashText;

};

