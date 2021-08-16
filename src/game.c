#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

#include "../headers/game.h"
#include "../headers/snake.h"
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
    printf("%c", 223);
}

void erasePosition(int x, int y) {
    gotoxy(x, y);
    changeColorBlack();
    printf("%c", 255);
}

int getKey(int directions){
    int tecla = getch();
    switch (tecla) {
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
        score = 0,
        speed = 200,
        direction = 0,
        color;
    TBody body;
    TSnake* snake = (TSnake *) malloc(sizeof(TSnake));
    beginSnake(snake);
    system("cls");
    createCobra(snake);
    //debbug snake
    //printSnake(snake);printf("\n");snake.color = getRandomColor();changeColorWhite();snake.code = snake->size;changeSnake(snake,snake);printSnake(snake);
    //printf("\n");snake.color = snake->front->next->body.color;snake.code = snake->size;changeSnake(snake,snake);printSnake(snake);printf("\n");system("pause");
    system("cls");
    printBorders();
    printInfosGrid();
    printInfosInGame(nickname, score, snake->size);
    printGround();
    body.color  = insertFood(&foodX,&foodY);
    body.code = snake->size;
    
    while(1){
        while(!kbhit()){

        Sleep(speed);
            
            if(y==4||y==25||x==34||x==(WIDTH+24)){
                freeSnake(snake);
                return score;
            }
            //erasePosition(x,y);
            
            changePositions(&x,&y,direction);
            //CheckFood
            if(x==foodX&&y==foodY){
                erasePosition(x,y);
                changeSnake(body, snake);
                score += 10*snake->size;
                body.color  = insertFood(&foodX,&foodY);
                body.code = snake->size;   
                printInfosInGame(nickname, score, snake->size);
                speed-=5;
            }
            //random movement snake
            //rand()%2==0?x++:x--;rand()%2==0?y++:y--;
            //target food snake
            //if(x!=foodX){if(x<foodX){x++;}else{x--;}}if(y!=foodY){if(y<foodY){y++;}else{y--;}}
            setColor(snake->front->next->body.color);
            walkToPosition(x, y);
        }
        direction = getKey(direction);
    }
}