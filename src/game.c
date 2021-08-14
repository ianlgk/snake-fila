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
int getKey(int directions){
    int tecla = getch();
    switch (tecla)
        {
        case 72://^
            return 0;
            break;
         case 75://<-
            return 1;
            break;
         case 77://->
            return 2;
            break;
         case 80://\/
            return 3;
            break;
         default:
            return directions;
            break;
        }
}
void changePositions(int *x,int *y,int directions){
    gotoxy(0, 0);
    changeColorWhite();
    printf("x = %d, y = %d d= %d", *x, *y,directions);
    switch (directions)
        {
        case 0:
            (*y)--;
            break;
         case 1:
            (*x)--;
            break;
         case 2:
            (*x)++;
            break;
         case 3:
            (*y)++;
            break;
        default:
            break;
        }
}
int gameExe(char* nickname){
    int foodX,foodY,
        x = (WIDTH/2)+34,
        y = (HEIGHT/2)+4,
        score = 4550,
        speed = 1000,
        direction=0,
        color;
    TSnake snake;
    TFila* fila = (TFila *) malloc(sizeof(TFila));
    FFVazia( fila );
    system("cls");
    StartCobra(fila);
    //debbug fila
    //ImprimirFila(fila);printf("\n");snake.cor = getRandomColor();changeColorWhite();snake.codigo = fila->tamanho;ChangeSnake(snake,fila);ImprimirFila(fila);
    //printf("\n");snake.cor = fila->frente->prox->item.cor;snake.codigo = fila->tamanho;ChangeSnake(snake,fila);ImprimirFila(fila);printf("\n");system("pause");
    system("cls");
    printBorders();
    printInfosGrid();
    printInfosInGame(nickname, score, fila->tamanho);
    printGround();
        snake.cor  = insertFood(&foodX,&foodY);
        snake.codigo = fila->tamanho;
    
   
    
    while(1){
        
        Sleep(speed);
        if(y==4||y==25||x==34||x==(WIDTH+24)){
            return score;
        }
        erasePosition(x,y);
        if(kbhit()) direction = getKey(direction);
        changePositions(&x,&y,direction);
        //CheckFood
        if(x==foodX&&y==foodY){
            erasePosition(x,y);
            ChangeSnake(snake,fila);
            score += 10*fila->tamanho;
            snake.cor  = insertFood(&foodX,&foodY);
            snake.codigo = fila->tamanho;   
            printInfosInGame(nickname, score, fila->tamanho);
            speed-=20;
        }
        //random movement snake
        //rand()%2==0?x++:x--;rand()%2==0?y++:y--;
        //target food snake
        //if(x!=foodX){if(x<foodX){x++;}else{x--;}}if(y!=foodY){if(y<foodY){y++;}else{y--;}}
        setColor(fila->frente->prox->item.cor);
        walkToPosition(x, y);
    }

}