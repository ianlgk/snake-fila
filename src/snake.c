#include <stdlib.h>
#include <stdio.h>

#include "../headers/game.h"
#include "../headers/snake.h"
#include "../headers/interface.h"
#include "../headers/customization.h"

void beginSnake(TSnake *Snake){
    Snake->front = (TCell*) malloc(sizeof(TCell));
    Snake->back = Snake->front;
    Snake->front->next = NULL;
    Snake->size = 0;
}

int isEmpty(TSnake Snake){
    return (Snake.front == Snake.back);
}

void line(TBody x, TSnake *Snake){
    Snake->back->next = (TCell*) malloc(sizeof(TCell));
    Snake->back = Snake->back->next;
    Snake->back->body = x;
    Snake->back->next = NULL;
    Snake->size++;
}

void freeSnake(TSnake *Snake){
    TBody auxBody;
    while(!isEmpty(*Snake)){
        unline(Snake, &auxBody);
    }
    free(Snake->front);
}

void unline(TSnake *Snake, TBody *Item){
    TCell* aux;
    if (!isEmpty(*Snake)){
        aux = Snake->front->next;
        Snake->front->next = aux->next;
        *Item = aux->body;
        free(aux);
        if (Snake->front->next == NULL)
            Snake->back = Snake->front;
        Snake->size--;
    }
}

void printSnake(TSnake *Snake){
    TBody auxBody;
    int N;
    N = Snake->size;
    while(N > 0){
        unline(Snake, &auxBody);
        setColor(auxBody.color);
        printf("cod: %d color: %d\n",auxBody.code,auxBody.color);
        line(auxBody,Snake);
        N--;
    }
}

int changeSnake(TBody body,TSnake *snake){
        TBody aux;
        unline(snake,&aux);
        if(aux.color==body.color){
            for (int i = 0; i < snake->size; i++){
                unline(snake,&aux);
                aux.code--;
                line(aux,snake);
            }
            return 0;
        }else{
            line(aux,snake);
            for (int i = 0; i < snake->size-1; i++){
                unline(snake,&aux);
                line(aux,snake);
            }
            line(body,snake);
            return 1;
        }
}

void createCobra(TSnake *snake){
    int color;
    TBody aux;
    for (int i = 0; i < START_SIZE; i++){
        color = getRandomColor();
        aux.code = i;
        aux.color = color;
        line(aux,snake);
    }
    changeColorWhite();
}