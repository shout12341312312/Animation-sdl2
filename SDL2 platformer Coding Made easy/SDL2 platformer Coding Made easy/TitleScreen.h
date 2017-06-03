#pragma once
#include "GameScreen.h"
#include "ScreenManager.h"
#include "SplashScreen.h"
#include "Texture.h"


class TitleScreen : public GameScreen
{
public:
	TitleScreen();
	~TitleScreen();

	void LoadContent(SDL_Renderer *renderer);
	void UnloadContent();
	void Update( SDL_Renderer *renderer, SDL_Event &event);
	void Draw(SDL_Renderer *renderer);

private:

	TTF_Font *font;
	SDL_Color color;
	SDL_Texture *textTexture;
	int textWidth, textHeight;

	Texture TitleText;
};

