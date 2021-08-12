#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

#include "../headers/game.h"
#include "../headers/interface.h"
#include "../headers/customization.h"

void printGround(){
    system("cls");
    printf("\n");
    for(int i = 0; i < height; i++){
           
       for (int j = 0; j < width; j++){
           if(j==(width-1)){
                 printf("%c\n",177);
                 continue;
            }
            if(i==0||j==0||j==1||i==height-1||j==width-2){
                printf("%c",177);
                continue;
            }
            
            printf("%c",255);
       } 
    }
}

void insertFood () {
    int y = (rand() % (height-5))+3;
    int x = (rand() % (width-5))+3;
    gotoxy(x,y);
    getRandomColor();
    printf("%c",254);
}

int gameExe(){
    srand(time(NULL));

    int x, cor, y;

    printGround(width,height);
    
    while (1) {
        insertFood();
        for (int i = 1; i < 10; i++){
            y = (rand() % (height-5))+3;
            x = (rand() % (width-5))+3;
            gotoxy(x,y);
            cor = getRandomColor();
            printf("%c",254);
            changeColorWhite();
            gotoxy(0,0);
            printf("x %d y %d",x,y);
            Sleep(2000);
        }
    }   
}