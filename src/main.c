#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "../headers/game.h"
#include "../headers/interface.h"

int main(int argc, char const *argv[]){
    system("cls");

    int option;
    char nickname[30];

    gameInformations();

    do {
        option = mainMenu();
        switch (option){
            case 1:
                gotoxy(45, 20);
                printf("Informe o seu nick: ");
                gotoxy(65, 20);
                fgets(nickname, 30, stdin);
                nickname[sizeof(nickname) - 1] = '\0';
                gameExe(nickname);
                Sleep(1000);
                break;
            case 2:
                creditsMenu();
                break;
            case 3:
                system("cls");
                printf("Finalizando jogo...\n\n");
                Sleep(3000);
                break;
            default:
                break;
        }
    } while(option != 3);

    return 0;
}