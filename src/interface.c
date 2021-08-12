#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#include "../headers/interface.h"
#include "../headers/game.h"
#include "../headers/customization.h"

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void gameInformations(){
    system("cls");
    printBorders();
    gotoxy(51, 14);
    changeColorYellow();
    printf("Jogo Snake em C\n\n");
    gotoxy(52, 15);
    changeColorRed();
    printf("UFOP");
    gotoxy(57, 15);
    changeColorWhite();
    printf("- AEDS I");
    gotoxy(3, 29);
    sleep(3);
}

int mainMenu(){
    int tecla, x, y;
    x = 0; y = 2;

    system("cls");
    printBorders();
    printTitle();/*
    printf("                 SNAKE\n\n");
    printf("   JOGAR        CREDITOS          SAIR");

    do{
        gotoxy(x, y);
        printf(">>");
        gotoxy(0, 10);
        tecla = getch();
        switch(tecla){
            case 13:                                        // quando pressiona enter
                switch(x){                                  // retorna a opçao
                    case 0:
                        return 1;
                        break;
                    case 13:
                        return 2;
                        break;
                    case 32:
                        return 3;
                        break;
                    default:
                        break;
                }
                break;
            case 75:                                            // quando pressiona <-
                if(x != 0){
                    if(x == 32){
                        gotoxy(x, y);
                        printf("  ");
                        x -= 19;
                    } else{
                        gotoxy(x, y);
                        printf("  ");
                        x -= 13;
                    }
                } else {
                    // não faz nada, pois já está na borda
                }
                break;
            case 77:                                        // quando pressiona ->
                if(x != 32){
                    if(x == 0){
                        gotoxy(x, y);
                        printf("  ");
                        x += 13;
                    } else{
                        gotoxy(x, y);
                        printf("  ");
                        x += 19;
                    }
                } else {
                    // não faz nada, pois já está na borda
                }
                break;
            default:
                break;
        }
    } while(tecla != 13);*/
    
    printf("\n\n");
}

void creditsMenu(){
    system("cls");
    printBorders();
    gotoxy(34, 9);
    changeColorRed();
    printf("UFOP");
    gotoxy(39, 9);
    changeColorWhite();
    printf("- Algoritmos e Estruturas de Dados I / 2021");
    gotoxy(49, 11);
    printf("Desenvolvido por:");
    gotoxy(38, 13);
    printf("20.1 | S.I - Ian Langkammer Batista");
    gotoxy(38, 14);
    printf("20.1 | S.I - Leonardo Moreira Sepulveda");
    gotoxy(38, 15);
    printf("20.1 | S.I - Rafael Caetano Texeira");
    gotoxy(38, 16);
    printf("20.1 | S.I - Victor Gabriel Siqueira Moura");
    gotoxy(38, 17);
    printf("18.1 | E.P - Paulo Cesar de Freitas Lagares");
    gotoxy(36, 19);
    changeColorCyan();
    printf("Repositorio:");
    gotoxy(49, 19);
    changeColorWhite();
    printf("github.com/LeoMoreiraS/snake-fila");
    gotoxy(3, 29);
    sleep(10);
}

void printBorders(){
    changeColorWhite();

    for (int i = 3; i < BORDER_WIDTH; i++){
        gotoxy(i, 2);
        if(i == 3)
            printf("%c", 201);
        else if(i + 1 == BORDER_WIDTH)
            printf("%c", 187);
        else
            printf("%c", 205);
    }

    for (int i = 3; i < BORDER_HEIGHT + 3; i++){
        gotoxy(3, i);
        printf("%c", 186);
        gotoxy(BORDER_WIDTH - 1, i);
        printf("%c\n", 186);
    }

    for (int i = 3; i < BORDER_WIDTH; i++){
        gotoxy(i, BORDER_HEIGHT + 2);
        if(i == 3)
            printf("%c", 200);
        else if(i + 1 == BORDER_WIDTH)
            printf("%c", 188);
        else
            printf("%c", 205);
    }
}

void printTitle(){
    // Bordas do título
    changeColorRed();
    for (int i = 5; i < 80; i++){
        gotoxy(i, 4);
        printf("%c", 219);
    }
    
    for (int i = 5; i < 15; i++){
        gotoxy(5, i);
        printf("%c", 219);
        gotoxy(80 - 1, i);
        printf("%c\n", 219);
    }
    
    for (int i = 5; i < 80; i++){
        gotoxy(i, 14);
        printf("%c", 219);
    }

    // Preencher o background do título
    changeColorCyan();
    for (int i = 6; i < 79; i++){
        for (int j = 5; j < 14; j++){
            gotoxy(i, j);
            printf("%c", 219);
        }
    }   

    changeColorWhite();
}