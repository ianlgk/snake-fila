#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
#include "../headers/filas.h"
#include "../headers/game.h"
#include "../headers/interface.h"
#include "../headers/customization.h"

int insertFood(int *x,int *y) {
    srand(time(NULL));
    *y = (rand() % (HEIGHT-3)) + 5;
    *x = (rand() % (WIDTH - 13)) + 36;
    gotoxy(0, 0);
    changeColorWhite();
    printf("x = %d, y = %d", *x, *y);
    gotoxy(*x, *y);
    int color = getRandomColor();
    printf("%c", 254);
    return color;
}

void walkToPosition(int x, int y) {
    gotoxy(x, y);
    getRandomColor();
    printf("%c",254);
}

void erasePosition(int x, int y) {
    gotoxy(x, y);
    changeColorBlack();
    printf("%c",255);
}
void StartCobra(TFila *fila){
    int color;
    TSnake aux;
    for (int i = 0; i < START_SIZE; i++){
        color = getRandomColor();
        aux.codigo = i;
        aux.cor = color;
        Enfileirar(aux,fila);
    }
    changeColorWhite();
    ImprimirFila(fila);
}

int gameExe(char* nickname){
    int foodX,foodY, x = 37, y = 7, score = 4550, nFoods = 12,color;
    TSnake snake;
    TFila* fila = (TFila *) malloc(sizeof(TFila));
    FFVazia( fila );
    StartCobra(fila);
    system("pause");
    system("cls");

    printBorders();
    printInfosGrid();
    printInfosInGame(nickname, score, nFoods);
    printGround();
    
    while (1) {
        
        color = insertFood(&foodX,&foodY);
        for (x; x < WIDTH +24; x++){
            walkToPosition(x, y);
            if (x != 37)
                erasePosition(x-1, y);
            changeColorWhite();
        }
        erasePosition(WIDTH + 23, y);
        x = 37;
        y = 7;
    }
}