#ifndef PADDLES_H_JOHN_03112015
#define PADDLES_H_JOHN_03112015
typedef struct paddle
{ 
    int x, y, dy, size; 
} Paddle;

typedef struct ball
{ 
    int x, y, dx, dy; 
} Ball;

void moveBall(Ball *);
void changeDX(int, Ball *);
void changeDY(int, Ball *);
void movePaddle(Paddle *);
void changePaddle(int, Paddle *);

#define woah

#endif
