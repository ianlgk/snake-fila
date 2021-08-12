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
    for(int i = 0; i < HEIGHT; i++){
           
       for (int j = 0; j < WIDTH; j++){
           if(j==(WIDTH-1)){
                 printf("%c\n",177);
                 continue;
            }
            if(i==0||j==0||j==1||i==HEIGHT-1||j==WIDTH-2){
                printf("%c",177);
                continue;
            }
            
            printf("%c",255);
       } 
    }
}

void insertFood () {
    int y = (rand() % (HEIGHT-5))+3;
    int x = (rand() % (WIDTH-5))+3;
    gotoxy(x,y);
    getRandomColor();
    printf("%c",254);
}

int gameExe(){
    srand(time(NULL));

    int x, color, y;

    printGround(WIDTH,HEIGHT);
    
    while (1) {
        insertFood();
        for (int i = 1; i < 10; i++){
            y = (rand() % (HEIGHT-5))+3;
            x = (rand() % (WIDTH-5))+3;
            gotoxy(x,y);
            color = getRandomColor();
            printf("%c",254);
            changeColorWhite();
            gotoxy(0,0);
            printf("x %d y %d",x,y);
            Sleep(2000);
        }
    }   
}