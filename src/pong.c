#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <math.h>
#include "paddles.h"
#include "screen.h"
#include "difficulty.h"
#include "logic.h"
#include <unistd.h>
    
int
main(int argc, char **argv){
    // Initializes the number of times the game will be played, 
    // the screen, and the difficulty level
    int bestOutOf = atoi(argv[argc - 1]);
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    int i = 0;
    difficulty(&i);

    Ball *ball = malloc(sizeof(Ball));
    ball->x = COLS / 2 - 2;
    ball->y = LINES / 2 - 1;
    ball->dx = 1;
    ball->dy = 1;

    Paddle *hum = malloc(sizeof(Paddle));
    hum->size = (int) pow((double) 2, (double) 4 - i);
    hum->x = 2;
    hum->y = LINES / 2 - hum->size / 2;
    hum->dy = 0;

    Paddle *comp = malloc(sizeof(Paddle));
    comp->size = (int) pow((double) 2, (double) i);
    comp->x = COLS - 3;
    comp->y = LINES / 2 - comp->size / 2;
    comp->dy = 0;

    char **array = buffer(hum, comp, ball);
    int randnumb;

    int test1 = 0;
    int test2 = 0;
    int testpad = 0;

    while(1){
        randnumb = rand() % 50;

        clear();
        paintBuffer(array);
        refresh();
        
        testHit(ball,comp,&test1);
        testHit(ball,hum,&test1);

        testWall(ball,&test1,&test2,&bestOutOf);

        if(ball->y - 2 >= comp->y && ball->y <= comp->y + comp->size - 1){
            testpad = 2;
        }
        else if(comp->y < ball->y){
            if(!(comp->y + comp->size + 1 == LINES)){
                testpad = 0;
            }
            else{
                testpad = 2;
            }
        }
        else if(comp->y > ball->y){
            if(!(comp->y == 1)){
                testpad = 1;
            }
            else{
                testpad = 2;
            }
        }

        switch(test1){
            case 0:
                changeDX(abs(ball->dx),ball);
                break;
            case 1:
                changeDX(abs(ball->dx) * -1,ball);
                testpad = 2;
                break;
        }

        switch(test2){
            case 0:
                changeDY(abs(ball->dy),ball);
                break;
            case 1:
                changeDY(abs(ball->dy) * -1,ball);
                break;
        }

        switch(testpad){
            case 0:
                changePaddle(1,comp);
                break;
            case 1:
                changePaddle(-1,comp);
                break;
            case 2:
                changePaddle(0,comp);
        } 

        timeout(1);
        int ch = getch();
        if(ch == KEY_DOWN){
            if(!(hum->y + hum->size + 1 >= LINES)){
                changePaddle(2,hum);
            }
            else{
                changePaddle(0,hum);
            }
        }
        else if(ch == KEY_UP){
            if(!(hum->y <= 1)){
                changePaddle(-2,hum);
            }
            else{
                changePaddle(0,hum);
            }
        }
        else if(ch == 27 || bestOutOf == -1){
            endwin();
            return 0;
        }
        else if(ch == KEY_HOME){
            timeout(1);
            ch = getch();
            while(!(ch == KEY_HOME)){
                if(ch == 27) {
                    endwin();
                    return 0;
                }
                timeout(1);
                ch = getch();
            }
        }
        else{
            changePaddle(0,hum);
        }

        comp->x = COLS -3;
        movePaddle(hum);
        if(!(randnumb == 0)){
            movePaddle(comp);
        }
        moveBall(ball);
        free(array);
        array = buffer(hum,comp,ball);

        usleep(25000);
    }
}
