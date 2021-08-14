#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

#include "../headers/game.h"
#include "../headers/interface.h"
#include "../headers/customization.h"

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

void changeColorBlack(){
    printf("\033[0;30m");
}

void changeColorRed(){
    printf("\033[0;31m");
}

void changeColorBgGreen(){
    printf("\e[42m");
}

int getRandomColor(){
    int color =rand()%5;
    switch (color)
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
    return color;
}
void setColor(int color){
    switch (color)
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
}