#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "paddles.h"

void moveBall(Ball *ball)
{
    ball->x = ball->x + ball->dx;
    ball->y = ball->y + ball->dy;
}

void changeDX(int dx, Ball *ball)
{
    ball->dx = dx;
}

void changeDY(int dy, Ball *ball)
{
    ball->dy = dy;
}

void movePaddle(Paddle *paddle)
{
    paddle->y = paddle->y + paddle->dy;
}

void changePaddle(int dy, Paddle *paddle)
{
    paddle->dy = dy;
}
