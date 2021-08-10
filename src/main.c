#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../headers/interface.h"

int main(int argc, char const *argv[]){
    system("cls");

    int option;

    printf("\nJogo Snake em C\n\n");
    printf("UFOP - AEDS I\n\n");
    sleep(3);

    do{
        mainMenu();
        printf("Informe a opcao: ");
        scanf("%d", &option);
        switch (option){
        case 1:
            system("cls");
            printf("\nJOGO\n\n");
            sleep(1);
            break;
        case 2:
            system("cls");
            printf("\nCRÉDITOS\n\n");
            sleep(1);
            break;
        case 3:
            system("cls");
            printf("\nFinalizando jogo...\n\n");
            sleep(1);
            break;
        default:
            break;
        }
    } while(option != 3);

    return 0;
}