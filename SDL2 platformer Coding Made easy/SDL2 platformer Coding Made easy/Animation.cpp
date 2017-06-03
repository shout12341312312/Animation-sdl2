#include "Animation.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::loadContent(SDL_Renderer *renderer, std::string FadeOutTexture, std::string FadeInTexture, int x, int y)
{
	this->posX = x;
	this->posY = y;

	FadeIn.loadFromFile(FadeInTexture, renderer);
	FadeOut.loadFromFile(FadeOutTexture, renderer);

	color = { 114,77,255 };

	active = false;

}

void Animation::UnloadContent()
{

}

void Animation::Draw(SDL_Renderer *renderer)
{   
	FadeIn.render(0, 0, renderer);
	FadeOut.render(0, 0, renderer);
}

void Animation::Update()
{

}

void Animation::SetAlpha(float value)
{
	alpha = value;
}

float Animation::getAlpha()
{
	return alpha;
}

void Animation::SetActive(bool value)
{
	active = value;
}