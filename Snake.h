#ifndef SNAKE_SDL_SNAKE_H
#define SNAKE_SDL_SNAKE_H

#include "Vector.h"
#include "SnakePart.h"

typedef struct Snake {
    int direction;
    int partsNb;
    SnakePart* head;
    SnakePart* tail;
} Snake;

Snake* snake_init(float x, float y,int dir);

void snake_addPart(Snake* s);
void snake_update(Snake* s);
void snake_display(Snake* s, SDL_Renderer* rend);

void snake_destruct();

#endif //SNAKE_SDL_SNAKE_H
