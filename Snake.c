#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Snake.h"
#include "const.h"

Snake* snake_init(float x, float y, int dir) {
    Snake* sn =  malloc(sizeof(Snake));
    if(sn == NULL) return NULL;

    sn->pos = vector_create(x, y);
    sn->direction = dir;
    sn->speed = 2;
    sn->head = snakepart_create(sn->pos->x, sn->pos->y);
    snake_addPart(sn);
    snake_addPart(sn);
}

void snake_addPart(Snake* s) {
    if(s == NULL) return;

    SnakePart* sPart = s->head;
    while(sPart->next != NULL)
        sPart = sPart->next;

    float nextPosX, nextPosY;
    switch (s->direction) {
        case LEFT:
            nextPosX = sPart->pos->x+1+SCALE;
            nextPosY = sPart->pos->y;
            break;
        case TOP:
            nextPosX = sPart->pos->x;
            nextPosY = sPart->pos->y+1+SCALE;
            break;
        case RIGHT:
            nextPosX = sPart->pos->x+1 - SCALE;
            nextPosY = sPart->pos->y;
            break;
        case DOWN:
            nextPosX = sPart->pos->x;
            nextPosY = sPart->pos->y+1 - SCALE;
            break;
    }

    sPart->next = snakepart_create(nextPosX,nextPosY);
    ++s->partsNb;
}

void snake_display(Snake* s, SDL_Renderer* rend) {
    if(s == NULL) return;
    SnakePart* part = s->head;
    while(part != NULL) {
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        SDL_Rect rect = {part->pos->x, part->pos->y, SCALE, SCALE};
        SDL_RenderFillRect(rend, &rect);
        part = part->next;
    }
}

void snake_destruct() {

}