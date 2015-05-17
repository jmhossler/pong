#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
    int i,empty = 10, len = 10, test1 = 1, test2 = 1;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    while(1){
	    clear(); 
        timeout(1);
        int ch = getch();
        //if(!(ch == -1)){
        //    printw("%d\n",ch);
        //    refresh();
        //    sleep(1);
        //}
        switch(ch){
            case KEY_DOWN:
                test1 = 1;
                break;
            case KEY_UP:
                test1 = 0;
                break;
            case KEY_LEFT:
                test2 = 0;
                break;
            case KEY_RIGHT:
                test2 = 1;
                break;
            case 27:
                endwin();
                return 0;
        }

        for(i = 0; i < empty; ++i){
            printw("\n");
        }
        for(i = 0; i < len; ++i){
            printw(" ");
        }
        printw("* * *\n");
    	for(i = 0; i < len; ++i){
            printw(" ");
        }
        printw("* * *\n");
        for(i = 0; i < len; ++i){
            printw(" ");
        }
        printw("* * *\n");
	    refresh();
        if(empty > LINES - 4){
            test1 = 0;
        }
        else if(empty <= 0){
            test1 = 1;
        }

        if(len > COLS - 6){
            test2 = 0;
        }
        else if(len <= 0){
            test2 = 1;
        }
        
        switch(test1){
            case 1:
                ++empty;
                break;
            case 0:
                --empty;
                break;
        }
        switch(test2){
            case 1:
                ++len;
                break;
            case 0:
                --len;
                break;
        }

        usleep(10000);
    }

    return 0;
}
