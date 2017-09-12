#include <SDL2/SDL.h>
#include <stdio.h>
#include "const.h"
#include "graphics.h"
#include "Snake.h"

int main() {
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	int quit = 0;
    SDL_Event e;

	int timer; //delta time in seconds

	window = initVideo("Snake");
	if(window == NULL) printf("Failed to initalize\n");
	else {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL) {
			printf("Renderer could not be created ! SDL_Error: %s\n", SDL_GetError());
		} else {

            Snake* snake = snake_init(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,RIGHT);
			if(snake == NULL) {
				printf("Snake could not be initialized\n");
			} else {

				while (!quit) {

					while (SDL_PollEvent(&e) != 0) {
						if (e.type == SDL_QUIT) {
							quit = 1;
						} else if( e.type == SDL_KEYDOWN ) { //Select surfaces based on key press
							 switch( e.key.keysym.sym ) {
								 case SDLK_UP:
									 if(snake->direction != DOWN)
									 	snake->direction = TOP;
									 break;
								 case SDLK_DOWN:
									 if(snake->direction != TOP)
									 	snake->direction = DOWN;
									 break;
								 case SDLK_LEFT:
									 if(snake->direction != RIGHT)
									 	snake->direction = LEFT;
									 break;
								 case SDLK_RIGHT:
									 if(snake->direction != LEFT)
									 	snake->direction = RIGHT;
									 break;
								 default:
									 break;
							 }
						}
					}
					timer = SDL_GetTicks();

					SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
					SDL_RenderClear(renderer);

					snake_update(snake);
					snake_display(snake, renderer);

					timer = SDL_GetTicks() - timer;
					if(timer < 1000/FRAMERATE)
					{
						SDL_Delay((1000/FRAMERATE) - timer);
					}

					SDL_RenderPresent(renderer);
				}
			}
		}
	}
	closeVideo(renderer, window);
	return 0;
}
