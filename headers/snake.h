#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define START_SIZE 5

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
void enqueue(TBody x, TSnake *Snake);
void dequeue(TSnake *Snake, TBody *Item);
void freeSnake(TSnake *Snake);
void printSnake(TSnake *Snake);
int  changeSnake(TBody body,TSnake *snake);
void createCobra(TSnake *snake,int x,int y);
/* Functions */

#endif // SNAKE_H_INCLUDED