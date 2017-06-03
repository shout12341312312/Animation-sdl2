#include "header.h"
#include "ScreenManager.h"

int main(int argc, char *args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Window *window = SDL_CreateWindow("SDL Platformer Coding Made Easy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	bool quit = false;
	SDL_Event event;

	ScreenManager::GetInstance().Initialize(renderer);
	ScreenManager::GetInstance().LoadContent(renderer);

	SDL_Rect Fade = { 0,0,ScreenWidth, ScreenHeight };

	float FPStime = 0;
	float frameTime = 0;
	float MIN_FRAME_TIME = 3.333f;

	FPStime = SDL_GetTicks();
	while (!quit)
	{
		frameTime = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return 0;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		SDL_RenderClear(renderer);

		ScreenManager::GetInstance().Update(renderer, event);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255 * ScreenManager::GetInstance().GetAlpha());
		SDL_RenderFillRect(renderer, &Fade);

		ScreenManager::GetInstance().Draw(renderer);

		SDL_RenderPresent(renderer);

		if (SDL_GetTicks() - frameTime < MIN_FRAME_TIME) 
		{
			SDL_Delay(MIN_FRAME_TIME - (SDL_GetTicks() - frameTime));
		}
	}
	return 0;
}