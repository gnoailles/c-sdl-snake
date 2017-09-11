#ifndef SNAKE_SDL_SNAKE_H
#define SNAKE_SDL_SNAKE_H

#include "Vector.h"
#include "SnakePart.h"

typedef struct Snake {
    Vector* pos;
    int direction;
    float speed;
    int partsNb;
    SnakePart* head;
} Snake;

Snake* snake_init(float x, float y,int dir);

void snake_addPart(Snake* s);
void snake_display(Snake* s, SDL_Renderer* rend);

void snake_destruct();

#endif //SNAKE_SDL_SNAKE_H
