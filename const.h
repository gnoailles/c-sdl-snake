#ifndef CONST_H
#define CONST_H

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define SCALE 25
#define COLS (int)floor(SCREEN_WIDTH / SCALE)
#define ROWS (int)floor(SCREEN_HEIGHT / SCALE)

typedef enum {
    LEFT,
    TOP,
    RIGHT,
    DOWN
}directions;

#endif
