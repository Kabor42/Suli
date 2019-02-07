#ifndef __CURSE_H__
#define __CURSE_H__

#include <ncurses.h>

#include "stuff.h"

typedef struct myWin {
    int row, col;
    int x, y;
    WINDOW *win;
} myWin;

typedef enum ALIGN {
    NO,
    NE,
    NW,
    EA,
    WE,
    SO,
    SE,
    SW,
    CENTER,
    FULL
} ALIGN;

myWin *createWindow(
        int rows,
        int cols,
        bool border,
        char *title,
        ALIGN pos
);

void deleteWindow(myWin *win);

myWin *createCal(Rekord *this);

Rekord *newRecord();

char *nGetPasswd();

Rekord *addRecord(Rekord *root, Rekord *new);

void nKiir(Rekord *this);

void run(Rekord *root);

menuItem nMenu();

#endif //__CURS_H__