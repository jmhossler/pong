#include "logic.h"
#include <curses.h>

void testHit(Ball *ball, Paddle *paddle, int *test)
{
    if (ball->y + 2 >= paddle->y && ball->y <= paddle->y + paddle->size) {
        if (ball->x + 5 == paddle->x)
            *test = 1;
        if (ball->x == paddle->x + 2)
            *test = 0;
    }
}
           
void testWall(Ball *ball, int *test1, int *test2, int *rounds)
{
    if (ball->x + 4 == COLS) {
        *test1 = 1;
        *rounds = *rounds - 1;
    }
    if (ball->x == 0) {
        *test1 = 0;
        *rounds = *rounds - 1;
    }
    if (ball->y + 4 >= LINES) {
        *test2 = 1;
    }
    if (ball->y == 1) {
        *test2 = 0;
    }
}

