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
    printf("%c", 219);
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
    /* important variables */
    int foodX,foodY,
        x = (WIDTH/2)+34,
        y = (HEIGHT/2)+4,
        score = 0,
        speed = 200,
        direction = 0,
        color,
        auX,
        auY
        ;
    TBody food,body,bodyAux,temp;
    TSnake* snake = (TSnake *) malloc(sizeof(TSnake));
    /* important variables */

    beginSnake(snake);
    system("cls");
    createCobra(snake,x,y);
    //debbug snake
    //printSnake(snake);printf("\n");snake.color = getRandomColor();changeColorWhite();snake.code = snake->size;changeSnake(snake,snake);printSnake(snake);
    //printf("\n");snake.color = snake->front->next->body.color;snake.code = snake->size;changeSnake(snake,snake);printSnake(snake);printf("\n");system("pause");
    system("cls");
    printBorders();
    printInfosGrid();
    printInfosInGame(nickname, score, snake->size);
    printGround();
    food.color  = insertFood(&foodX,&foodY);
    food.code = snake->size;
    
    while(1){
        gotoxy(3, 29);
        while(!kbhit()){
            //check collision
            if(y == 4 || y == 25 || x == 34 || x == (WIDTH + 24)){
                freeSnake(snake);
                gameOver(&x, &y);
                return score;
            }
        

            Sleep(speed);
            
            
            //CheckFood
            
            if(x==foodX&&y==foodY){
                changeSnake(food, snake);
                score += 10*snake->size;
                food.color  = insertFood(&foodX,&foodY);
                food.code = snake->size;   
                printInfosInGame(nickname, score, snake->size);
                speed-=5;
            }
            
            dequeue(snake,&body);
            bodyAux = body;
            changePositions(&x,&y,direction);
            body.x = x;
            body.y = y;
            enqueue(body,snake);
            setColor(body.color);
            walkToPosition(x, y);
            for(int i=1; i<snake->size; i++){
                dequeue(snake,&body);
                temp.x=body.x;
                temp.y=body.y;
                body.x=bodyAux.x;
                body.y=bodyAux.y;
                bodyAux.x = temp.x;
                bodyAux.y = temp.y;
                setColor(body.color);
                walkToPosition(body.x, body.y);
                enqueue(body,snake);
                //collision snake snake
                if(x==body.x&&y==body.y){
                    freeSnake(snake);
                    gameOver(&x, &y);
                    return score;
                }
            }
            erasePosition(bodyAux.x,bodyAux.y);
            gotoxy(3, 29);  
        }
        direction = getKey(direction);
    }
}

 //random movement snake
            //rand()%2==0?x++:x--;rand()%2==0?y++:y--;
            //target food snake
            //if(x!=foodX){if(x<foodX){x++;}else{x--;}}if(y!=foodY){if(y<foodY){y++;}else{y--;}}
            //for (int i = 0; i < snake->size; i++) {