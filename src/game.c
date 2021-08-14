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
    printf("%c",254);
}

void erasePosition(int x, int y) {
    gotoxy(x, y);
    changeColorBlack();
    printf("%c",255);
}
int ChangeSnake(TSnake snake,TFila *fila){
        TSnake aux;
        int cod=0;
        Desenfileirar(fila,&aux);
        if(aux.cor==snake.cor){
            for (int i = 0; i < fila->tamanho; i++){
                Desenfileirar(fila,&aux);
                aux.codigo--;
                Enfileirar(aux,fila);
            }
            return 0;
        }else{
            Enfileirar(aux,fila);
            for (int i = 0; i < fila->tamanho-1; i++){
                Desenfileirar(fila,&aux);
                Enfileirar(aux,fila);
            }
            Enfileirar(snake,fila);
            return 1;
        }
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
    
}

int gameExe(char* nickname){
    int foodX,foodY, x = 37, y = 7, score = 4550, nFoods = 12,color;
    TSnake snake;
    TFila* fila = (TFila *) malloc(sizeof(TFila));
    FFVazia( fila );
    system("cls");
    StartCobra(fila);
    //Inicio debbug inserção cobra
    /*ImprimirFila(fila);
    printf("\n");
    snake.cor = getRandomColor();
    changeColorWhite();
    snake.codigo = fila->tamanho;
    ChangeSnake(snake,fila);
    ImprimirFila(fila);
    printf("\n");
    snake.cor = fila->frente->prox->item.cor;
    snake.codigo = fila->tamanho;
    ChangeSnake(snake,fila);
    ImprimirFila(fila);
    printf("\n");
    system("pause");*/
    //fim debbug
    system("cls");
    printBorders();
    printInfosGrid();
    printInfosInGame(nickname, score, fila->tamanho);
    printGround();
    
    while (1) {
        
        snake.cor  = insertFood(&foodX,&foodY);
        snake.codigo = fila->tamanho;
        while(1){
            
           
            erasePosition(x,y);
            if(x!=foodX){
                if(x<foodX){
                    x++;
                }else{
                    x--;
                }
            }
            if(y!=foodY){
                if(y<foodY){
                    y++;
                }else{
                    y--;
                }    
            }
            walkToPosition(x, y);
            //CheckFood
            if(x==foodX&&y==foodY){
                erasePosition(x,y);
                ChangeSnake(snake,fila);
                score += 10*fila->tamanho;
                printInfosInGame(nickname, score, fila->tamanho);
                break;
            }
            if (x != 37)
                erasePosition(x-1, y);
            changeColorWhite();
            Sleep(100);
        }
        erasePosition(WIDTH + 23, y);
        x = 37;
        y = 7;
    }
}