#pragma once
#include "Animation.h"

class FadeAnimation : public Animation
{
public:
	FadeAnimation();
	~FadeAnimation();

	void loadContent(SDL_Renderer *renderer, std::string FadeOutTexture, std::string FadeInTexture, int x, int y);
	void UnloadContent();
	void Update();
	void Draw(SDL_Renderer *renderer);

	void SetAlpha(float value);

private:

	bool increase;
	float fadeSpeed;

};

