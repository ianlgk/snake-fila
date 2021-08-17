#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define START_SIZE 5 // Define o tamanho inicial da cobra

typedef struct body
{
    int code;
    int color;
    int x;
    int y;
} TBody;

typedef struct cell
{
    TBody body;
    struct cell *next;
} TCell;

typedef struct snake
{
    TCell *front;
    TCell *back;
    int size;
} TSnake; // Estrutura de dados tipo Fila para cobra

/* Funções */

void beginSnake(TSnake *Snake);                               // Cria e inicializa a fila (cobra)
int isEmpty(TSnake Snake);                                    // Verifica se a fila (cobra) está vazia
void enqueue(TBody x, TSnake *Snake);                         // Aumenta o tamanho da fila (cobra) enfileirando
void dequeue(TSnake *Snake, TBody *Item);                     // Diminui o tamanho da fila (cobra) desenfileirando
void freeSnake(TSnake *Snake);                                // Libera memória alocada para a fila (cobra)
void printSnake(TSnake *Snake);                               // Printa a fila (cobra) na aplicação
int changeSnake(TBody body, TSnake *snake, TSnake *poopWall); // Modifica a estrutura fila (cobra) utilizando os métodos "enqueue" e "dequeue"
void createCobra(TSnake *snake, int x, int y);                // Inicializa o corpo da cobra

/* Funções */

#endif // SNAKE_H_INCLUDED