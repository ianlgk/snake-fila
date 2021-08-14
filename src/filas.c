#include <stdlib.h>
#include <stdio.h>
#include "../headers/filas.h"
#include "../headers/customization.h"

void FFVazia(TFila *Fila)
{
    Fila->frente =
        (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila Fila)
{
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TSnake x, TFila *Fila)
{
    Fila->tras->prox =
        (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TSnake *Item){
    TCelula* aux;
    if (!Vazia(*Fila)){
        aux = Fila->frente->prox;
        Fila->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
}
void ImprimirFila(TFila *Fila){
    TSnake auxItem;
    int N;
    N = Fila->tamanho;
    while(N > 0){
        Desenfileirar(Fila, &auxItem);
        printf("cod: %d cor: %d\n",auxItem.codigo,auxItem.cor);
        setColor(auxItem.cor);
        Enfileirar(auxItem,Fila);
        N--;
    }
}


