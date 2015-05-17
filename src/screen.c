#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "paddles.h"
#include "screen.h"
#include "difficulty.h"
#include <curses.h>
#include <unistd.h>

char **
buffer(Paddle *h, Paddle *c, Ball *b){
    int i,j,count = 0,lines = LINES, cols = COLS;


    char *score = "Player 1 | Computer";

    char **array = malloc(sizeof(char *) * lines);

    for(i = 0; i < lines; ++i){
        array[i] = malloc(sizeof(char) * cols);
    }

    for(i = 0; i < cols; ++i){
        if(i >= cols / 2 - (int) (strlen(score) / 2) && i <= cols / 2 + (int) (strlen(score) / 2)){
            array[0][i] = score[count];
            ++count;
        }
	    else if(i == cols){
            array[0][i] = '\n';
        }
        else{
            array[0][i] = ' ';
        } 
    }

    for(i=1;i < lines;++i){
        for(j=0;j < cols;++j){
            if(j == (int) (cols / 2)){
                array[i][j] = '|';
            }
            else{
                if(j == cols){
                    array[i][j] = '\n';
                }
                else{
                    array[i][j] = ' ';
                }
            }
        }
    }

    int posx = b->x;
    int posy = b->y;
    for(i = 0; i < 3; ++i){
        for(j = 0; j < 5; ++j){
            if(j % 2 == 0){
                array[posy + i][posx + j] = '*';
            }
            else{
                array[posy + i][posx + j] = ' ';
            }
        }
    }
    posx = h->x;
    posy = h->y;
    for(i = 0; i < h->size; ++i){
        for(j = 0; j < 2; ++j){
            array[posy + i][posx + j] = '|';
        }
    }

    posx = c->x;
    posy = c->y;
    for(i = 0; i < c->size; ++i){
        for(j = 0; j < 2; ++j){
            array[posy + i][posx + j] = '|';
        }
    }

    return array;
}

void
paintBuffer(char **buffer){
    int i,j;
    for(i=0; i < LINES; ++i){
        for(j=0; j < COLS; ++j){
            printw("%c",buffer[i][j]);
        }
    }
}

char *join(const char* s1, const char* s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    if(result){
        strcpy(result, s1);
        strcpy(result, s2);
    }

    return result;
}

/*int
main(){
    initscr();
    Ball *ball = malloc(sizeof(Ball));
    ball->x = COLS / 2 - 2;
    ball->y = LINES / 2 - 1;
    ball->dx = 1;
    ball->dy = 1;
    Paddle *hum = malloc(sizeof(Paddle));
    hum->x = 2;
    hum->y = 2;
    hum->dy = 0;
    Paddle *comp = malloc(sizeof(Paddle));
    comp->x = COLS - 3;
    comp->y = 2;
    comp->dy = 0;
    char **array = buffer(hum, comp, ball);

    while(1){
        clear();
        paintBuffer(array);
        refresh();
        timeout(1);
        int ch = getch();
        if(ch == 27){
            endwin();
            return 0;
        }
        array = buffer(hum,comp,ball);

        usleep(50000);
    }
}*/
