#include <stdlib.h>
#include "SnakePart.h"

SnakePart* snakepart_create(float x,float y) {
    SnakePart* snp = malloc(sizeof(SnakePart));
    if(snp == NULL) return NULL;

    snp->pos = vector_create(x,y);
    snp->next = NULL;

}
