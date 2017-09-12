#include <stdlib.h>
#include "SnakePart.h"
#include "const.h"

SnakePart* snakepart_create(float x,float y) {
    SnakePart* snp = malloc(sizeof(SnakePart));
    if(snp == NULL) return NULL;

    snp->pos = vector_create(x,y);
    snp->next = NULL;
    snp->prev = NULL;

}

void snakePart_getNextPos(SnakePart const* sp,int dir, float* x, float* y){
    switch (dir) {
        case LEFT:
            *x = sp->pos->x-1-SCALE;
            *y = sp->pos->y;
            break;
        case TOP:
            *x = sp->pos->x;
            *y = sp->pos->y-1-SCALE;
            break;
        case RIGHT:
            *x = sp->pos->x+1+SCALE;
            *y = sp->pos->y;
            break;
        case DOWN:
            *x = sp->pos->x;
            *y = sp->pos->y+1+SCALE;
            break;
    }
}
