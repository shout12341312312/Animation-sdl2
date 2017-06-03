#pragma once

#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "FadeAnimation.h"

#define ScreenWidth 1280
#define ScreenHeight 720

class ScreenManager
{
public:
	~ScreenManager();
	static ScreenManager &GetInstance();

	void Initialize(SDL_Renderer *renderer);
	void LoadContent(SDL_Renderer *renderer);
	void UnloadContent();
	void Update(SDL_Renderer *renderer, SDL_Event &event);
	void Draw (SDL_Renderer *renderer);
	void AddScreen(GameScreen *screen, SDL_Renderer *renderer);

	float GetAlpha();

private:

	void Transition(SDL_Renderer *renderer);
	bool transition;

	GameScreen *currentScreen, *newScreen;

	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator = (ScreenManager const&);

	FadeAnimation fade;

};

