#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#include "../headers/interface.h"

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void gameInformations(){
    system("cls");
    printf("Jogo Snake em C\n\n");
    printf(" UFOP - AEDS I");
    gotoxy(0, 10);
    sleep(3);
}

int mainMenu(){
    int tecla, x, y;
    x = 0; y = 2;

    system("cls");
    printf("                  SNAKE\n\n");
    printf("   JOGAR        CRÉDITOS          SAIR");

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
    } while(tecla != 13);
    
    printf("\n\n");
}

void creditsMenu(){
    system("cls");
    printf("\nUFOP - Algoritmos e Estruturas de Dados I / 2021\n\n");
    printf("Desenvolvido por: \n");
    printf("20.1 | S.I - Ian Langkammer Batista\n");
    printf("20.1 | S.I - Leonardo Moreira Sepulveda\n");
    printf("20.1 | S.I - Rafael Caetano Texeira\n");
    printf("20.1 | S.I - Victor Gabriel Siqueira Moura\n");
    printf("18.1 | E.P - Paulo César de Freitas Lagares\n\n");
    printf("Repositório: github.com/LeoMoreiraS/snake-fila\n\n");
    sleep(5);
}