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

	window = initVideo("Snake");
	if(window == NULL) printf("Failed to initalize\n");
	else {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == NULL) {
			printf("Renderer could not be created ! SDL_Error: %s\n", SDL_GetError());
		} else {

            Snake* snake = snake_init(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,TOP);

            while(!quit){

                while(SDL_PollEvent(&e) !=0) {
                    if(e.type == SDL_QUIT) {
                        quit = 1;
                    }
                }
                SDL_SetRenderDrawColor(renderer, 20, 20, 20, 0);
				SDL_RenderClear(renderer);



                snake_display(snake,renderer);



				SDL_RenderPresent(renderer);
            }
		}
	}
	closeVideo(renderer, window);
	return 0;
}
