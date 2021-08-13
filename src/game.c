#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

#include "../headers/game.h"
#include "../headers/interface.h"
#include "../headers/customization.h"

void printGround(){
    changeColorRed();
    // Printa o limite superior do campo
    for (int i = 34; i < WIDTH + 25; i++){
        gotoxy(i, 4);
        printf("%c", MURO);
    }

    // Printa os limites laterais do campo
    for (int i = 5; i < HEIGHT + 2; i++){
        gotoxy(34, i);
        printf("%c", MURO);
        gotoxy(24+WIDTH, i);
        printf("%c", MURO);
    }
    
    // Printa o limite inferior do campo
    for (int i = 34; i < WIDTH + 25; i++){
        gotoxy(i, 25);
        printf("%c", MURO);
    }
}

void insertFood(int *x,int *y) {
    srand(time(NULL));
    *y = (rand() % (HEIGHT)) + 3;
    *x = (rand() % (WIDTH - 13)) + 36;
    gotoxy(0, 0);
    changeColorWhite();
    printf("x = %d, y = %d", *x, *y);
    gotoxy(*x, *y);
    getRandomColor();
    printf("%c", 254);
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

int gameExe(char* nickname){
    int foodX,foodY, x = 35, y = 4, score = 4550, nFoods = 12;
  
    system("cls");

    printBorders();
    printInfosGrid();
    printInfosInGame(nickname, score, nFoods);
    printGround();
    
    while (1) {
        
        insertFood(&foodX,&foodY);
        for (x; x < WIDTH +24; x++){
            walkToPosition(x, y);
            if (x != 35)
                erasePosition(x-1, y);
            changeColorWhite();
        }
        erasePosition(WIDTH + 23, y);
        x = 35;
        y = 4;
    }
}