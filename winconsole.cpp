#include "winconsole.h"
#include <stdio.h>
#include <unistd.h>

void clrscr(void) {
    printf("\033[2J\033[H");
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}

void textcolor(int color) {
    printf("\033[1;%dm", color);
}

void clreol(void) {
    printf("\033[K");
}

void delay(int ms) {
    usleep(ms * 1000);
}
