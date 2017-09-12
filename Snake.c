#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Snake.h"
#include "const.h"

Snake* snake_init(float x, float y, int dir) {
    Snake* s =  malloc(sizeof(Snake));
    if(s == NULL) return NULL;

    s->direction = dir;
    s->tail = NULL;
    s->head = snakepart_create(x,y);
    snake_addPart(s);
    snake_addPart(s);
    return s;
}

void snake_addPart(Snake* s) {
    if(s == NULL) return;

    SnakePart* sp = s->head;
    while(sp->next != NULL)
        sp = sp->next;

    float nextPosX, nextPosY;
    snakePart_getNextPos(sp,s->direction,&nextPosX,&nextPosY);
    sp->next = snakepart_create(nextPosX,nextPosY);
    sp->next->prev = sp;
    s->tail = sp->next;
    if(sp->next == NULL) return;
    ++s->partsNb;
}

void snake_update(Snake* s) {
    if(s == NULL) return;
    SnakePart* part = s->tail;
    while(part != s->head) {
        part->pos->x= part->prev->pos->x;
        part->pos->y= part->prev->pos->y ;
        part = part->prev;
    }
    float nextPosX, nextPosY;
    snakePart_getNextPos(s->head,s->direction,&nextPosX,&nextPosY);
    s->head->pos->x = nextPosX;
    s->head->pos->y = nextPosY;

}

void snake_display(Snake* s, SDL_Renderer* rend) {

    if(s == NULL) return;
    SnakePart* part = s->head;
    SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
    SDL_Rect rect = {part->pos->x, part->pos->y, SCALE, SCALE};
    SDL_RenderFillRect(rend, &rect);
    part = part->next;
    while(part != NULL) {
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        SDL_Rect rect2 = {part->pos->x, part->pos->y, SCALE, SCALE};
        SDL_RenderFillRect(rend, &rect2);
        part = part->next;
    }
}

void snake_destruct() {

}