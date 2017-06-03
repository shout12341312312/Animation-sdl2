#pragma once
#include "header.h"
#include "Texture.h"

class Animation
{
public:
	Animation();
	~Animation();

	virtual void loadContent(SDL_Renderer *renderer, std::string FadeOutTexture, std::string FadeInTexture, int x, int y);
	virtual void UnloadContent();
	virtual void Update();
	virtual void Draw(SDL_Renderer *renderer);

	virtual void SetAlpha(float value);

	void SetActive(bool value);

	float getAlpha();

protected:

	Texture FadeIn, FadeOut;

	SDL_Color color;

	SDL_Rect sourceRect;

	float alpha;
	float posX, posY;

	bool active;
	

private:



};

