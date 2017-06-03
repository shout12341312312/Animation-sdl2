#include "Texture.h"



Texture::Texture()
{
	font = TTF_OpenFont("arial.ttf", 32);
	textTexture = NULL;
	textWidth = textHeight = 0;

	mWidth = mHeight = 0;
	mTexture = NULL;
}


Texture::~Texture()
{
	free();
}


void Texture::free()
{
	SDL_DestroyTexture(textTexture);
	SDL_DestroyTexture(mTexture);
	textTexture = NULL;
	textWidth = textHeight = 0;
	mWidth = mHeight = 0;
	mTexture = NULL;
}

void Texture::renderText(int x, int y, SDL_Renderer *renderer)
{
	SDL_Rect rect = { x,y, textWidth, textHeight };

	SDL_RenderCopy(renderer, textTexture, NULL, &rect);
}

bool Texture::loadText(std::string text, SDL_Color color,SDL_Renderer *renderer )
{
	SDL_Surface *loadedText = TTF_RenderText_Solid(font, text.c_str(), color);

	textTexture = SDL_CreateTextureFromSurface(renderer, loadedText);

	textWidth = loadedText->w;
	textHeight = loadedText->h;

	SDL_FreeSurface(loadedText);

	return textTexture != 0;
}

void Texture::render(int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect rect = { x,y,mWidth,mHeight };

	SDL_RenderCopy(renderer, mTexture, NULL, &rect);
}

bool Texture::loadFromFile(std::string path, SDL_Renderer *renderer)
{
	SDL_Texture *newTexture;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());

	newTexture =SDL_CreateTextureFromSurface(renderer, loadedSurface);

	mWidth = loadedSurface->w;
	mHeight = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);

	mTexture = newTexture;

	return mTexture;
}

void Texture::SetAlphaMode(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(textTexture, alpha);
}