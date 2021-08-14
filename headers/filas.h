#ifndef FILAS_H
#define FILAS_H
#include <stdlib.h>
#include <stdio.h>

typedef struct item
{
    int codigo;
    int cor;
} TSnake;

typedef struct celula
{
    TSnake item;
    struct celula* prox;
} TCelula;

typedef struct fila
{
    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TFila;
void FFVazia(TFila *Fila);
int Vazia(TFila Fila);
void Enfileirar(TSnake x, TFila *Fila);
void Desenfileirar(TFila *Fila, TSnake *Item);
void LiberarFila(TFila *Fila);
void ImprimirFila(TFila *Fila);

#endif // !FILAS.h