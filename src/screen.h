#ifndef SCREEN_H_JOHN_03112015
#define SCREEN_H_JOHN_03112015
#include "paddles.h"

char **buffer(Paddle *, Paddle *, Ball *);
void paintBuffer(char **);
char *join(const char *, const char *);
#endif
