#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define START_SIZE 2

typedef struct body {
    int code;
    int color;
    int x;
    int y;
} TBody;

typedef struct cell {
    TBody body;
    struct cell* next;
} TCell;

typedef struct snake {
    TCell* front;
    TCell* back;
    int size;
} TSnake;

/* Functions */
void beginSnake(TSnake *Snake);
int  isEmpty(TSnake Snake);
void line(TBody x, TSnake *Snake);
void unline(TSnake *Snake, TBody *Item);
void freeSnake(TSnake *Snake);
void printSnake(TSnake *Snake);
int  changeSnake(TBody body,TSnake *snake);
void createCobra(TSnake *snake);
/* Functions */

#endif // SNAKE_H_INCLUDED