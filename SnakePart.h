#ifndef SNAKE_SDL_SNAKEPART_H
#define SNAKE_SDL_SNAKEPART_H

#include "Vector.h"

typedef struct SnakePart {
    Vector* pos;
    struct SnakePart* next;
    struct SnakePart* prev;
} SnakePart;

SnakePart* snakepart_create(float x,float y);
void snakePart_getNextPos(SnakePart const* sp,int dir, float* x, float* y);

#endif //SNAKE_SDL_SNAKEPART_H
