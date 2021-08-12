
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
#include "../headers/game.h"
#include "../headers/interface.h"

void changeColorGreen(){
    printf("\033[0;32m");
}
void changeColorYellow(){
    printf("\033[0;33m");
}
void changeColorPurple(){
    printf("\033[0;35m");
}
void changeColorCyan(){
    printf("\033[0;36m");
}
void changeColorWhite(){
    printf("\033[0m");
}
void changeColorRed(){
    printf("\033[0;31m");
}
int geraCorAleatoria(){
    int cor =rand()%5;
    switch (cor)
    {
    case 0:
        changeColorRed();
        break;
    case 1:
        changeColorYellow();
        break;
    case 2:
        changeColorGreen();
        break;
    case 3:
        changeColorPurple();
        break;
    case 4:
        changeColorCyan();
        break;
    default:
        changeColorWhite();
        break;
    }
    return cor;

}

void gerarTela(){
    system("cls");
    printf("\n");
    for(int i = 0; i<VERTICAL; i++){
           
       for (int j = 0; j < HORIZONTAL; j++){
           if(j==(HORIZONTAL-1)){
                 printf("%c\n",219);
                 continue;
            }
            if(i==0||j==0||j==1||i==VERTICAL-1||j==HORIZONTAL-2){
                printf("%c",219);
                continue;
            }
            
            printf("%c",255);
       }
       
       
      
    }

}
int execute(){
    srand(time(NULL));
    int x;
    int cor;
    int y;
    gerarTela(HORIZONTAL,VERTICAL);
    
    for (int i = 1; i < 100; i++){
        y = (rand() % (VERTICAL-5))+3;
        x = (rand() % (HORIZONTAL-5))+3;
        gotoxy(x,y);
        cor = geraCorAleatoria();
        printf("%c",254);
        changeColorWhite();
        gotoxy(0,0);
        printf("                        ");
        gotoxy(0,0);
        printf("x %d y %d",x,y);
        Sleep(1000-i*10);
    }
    
}

