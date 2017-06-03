#include "FadeAnimation.h"



FadeAnimation::FadeAnimation()
{
}


FadeAnimation::~FadeAnimation()
{
}

void FadeAnimation::loadContent(SDL_Renderer *renderer,std::string FadeOutTexture, std::string FadeInTexture, int x, int y)
{
	increase = false;

	fadeSpeed = 0.001;
}

void FadeAnimation::UnloadContent()
{

}

void FadeAnimation::Draw(SDL_Renderer *renderer)
{
	Animation::Draw(renderer);
}

void FadeAnimation::Update()
{
	if (active)
	{
		if (!increase)
		{
			alpha -= fadeSpeed;
		}
		else
		{
			alpha += fadeSpeed;
		}

		if (alpha >= 1.0f)
		{
			alpha = 1.0f;
			increase = false;
		}
		else if (alpha <= 1.0f)
		{
			alpha = 0.0f;
			increase = true;
		}
	}
	else
	{
		alpha = 1.0f;
	}
}

void FadeAnimation::SetAlpha(float value)
{
	alpha = value;
	if (alpha = 0.0f)
		increase = true;
	else
		increase = true;
}