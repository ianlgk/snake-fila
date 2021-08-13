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

void insertFood(int *x,int *y) {
    srand(time(NULL));
    *y = (rand() % (HEIGHT-3)) + 5;
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
    int foodX,foodY, x = 37, y = 7, score = 4550, nFoods = 12;
  
    system("cls");

    printBorders();
    printInfosGrid();
    printInfosInGame(nickname, score, nFoods);
    printGround();
    
    while (1) {
        
        insertFood(&foodX,&foodY);
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