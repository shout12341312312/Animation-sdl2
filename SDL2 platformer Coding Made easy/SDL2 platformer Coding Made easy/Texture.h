#pragma once
#include "header.h"
class Texture
{
public:
	Texture();
	~Texture();
	bool loadText(std::string text, SDL_Color, SDL_Renderer *renderer);
	bool loadFromFile(std::string path, SDL_Renderer *renderer);

	void render(int x, int y, SDL_Renderer *renderer);
	void renderText(int x, int y, SDL_Renderer *renderer);
	void free();
	void SetAlphaMode(Uint8 alpha);
private:
	SDL_Texture *mTexture;
	SDL_Texture *textTexture;
	TTF_Font *font;

	int mWidth, mHeight;
	int textWidth, textHeight;
};

