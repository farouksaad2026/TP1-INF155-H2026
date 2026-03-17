#ifndef WINCONSOLE_H
#define WINCONSOLE_H

// Couleurs (simulées pour ANSI)
#define NOIR 30
#define ROUGE 31
#define VERT 32
#define JAUNE 33
#define BLEU 34
#define MAGENTA 35
#define CYAN 36
#define BLANC 37

void clrscr(void);
void gotoxy(int x, int y);
void textcolor(int color);
void clreol(void);
void delay(int ms);

#endif
