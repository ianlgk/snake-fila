#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "../headers/game.h"

#include "../headers/interface.h"

int main(int argc, char const *argv[]){

    int option;

    gameInformations();

    do{
        option = mainMenu();
        switch (option){
        case 1:
            execute();
            sleep(1);
            break;
        case 2:
            system("cls");
            creditsMenu();
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