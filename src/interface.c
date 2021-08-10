#include <stdio.h>
#include <stdlib.h>

#include "../headers/interface.h"

void gameInformations(){
    system("cls");
    printf("\nJogo Snake em C\n\n");
    printf(" UFOP - AEDS I\n");
    //sleep(3);
}

void mainMenu(){
    system("cls");
    printf("\nSNAKE\n\n");
    printf("JOGAR       ");
    printf("CRÉDITOS       ");
    printf("SAIR\n\n");
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
    system("pause");
    getchar();
}