#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curses.h>
#include "difficulty.h"

void difficulty(int *value)
{
    int i, ch;
    const char *question = "How difficult do you want this game to be?\n";
    const char *opt = "0 for easy, 1 for medium, 2 for hard, 3 for very hard, 4 for dragon-master\n";
    clear();

    for (i = 0; i < LINES / 2 - 2; ++i)
        printw("\n");

    for (i = 0; i < COLS / 2 - (int) strlen(question) / 2; ++i)
        printw(" ");

    printw("%s", question);

    for (i = 0; i < COLS / 2 - (int) strlen(opt) / 2; ++i)
        printw(" ");

    printw("%s", opt);
    for (i = 0; i < COLS / 2; ++i)
        printw(" ");

    refresh();
    ch = getch();
    printw("%d\n", ch);

    if (!(ch == 49 || ch == 48 || ch == 50 || ch == 51 || ch == 52)){
        difficulty(value);
    } else {
	    switch(ch) {
            case 48:
                *value = 0;
                break;
            case 49:
                *value = 1;
                break;
            case 50:
                *value = 2;
                break;
            case 51:
                *value = 3;
                break;
            case 52:
                *value = 4;
                break;
        }
    }
}
