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
    // Printa o limite superior do campo
    for (int i = 34; i < WIDTH + 25; i++){
        gotoxy(i, 3);
        printf("%c", MURO);
    }

    // Printa os limites laterais do campo
    for (int i = 4; i < HEIGHT + 3; i++){
        gotoxy(34, i);
        printf("%c", MURO);
        gotoxy(24+WIDTH, i);
        printf("%c", MURO);
    }
    
    // Printa o limite inferior do campo
    for (int i = 34; i < WIDTH + 25; i++){
        gotoxy(i, 26);
        printf("%c", MURO);
    }
}

void insertFood() {
    srand(time(NULL));
    int y = (rand() % (HEIGHT - 1)) + 4;
    int x = (rand() % (WIDTH - 12)) + 35;
    gotoxy(0, 0);
    changeColorWhite();
    printf("x = %d, y = %d", x, y);
    gotoxy(x, y);
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
    system("cls");

    printBorders();
    printInfosGrid();
    printGround();

    gotoxy(3, 28);
    
    while (1) {
        
        insertFood();
        for (int i = 35; i < WIDTH +24; i++){
            walkToPosition(i, 5);
            if (i != 35)
                erasePosition(i-1, 5);
            changeColorWhite();
            Sleep(100);
        }
        erasePosition(WIDTH - 3, 5);
    }
}