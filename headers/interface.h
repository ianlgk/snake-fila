#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#define BORDER_HEIGHT 25
#define BORDER_WIDTH 117

/* Functions */
int mainMenu();             // printa o menu principal
void creditsMenu();         // printa o menu de créditos
void gameInformations();    // printa a primeira tela ao iniciar o programa
void gotoxy(int x, int y);  // muda a posição da tela onde o cursor aponta
void printBorders();        // printa as bordas limitantes do programa
void printTitle();          // printa o título do jogo no mainMenu()
/* Functions */

# endif /* INTERFACE_H_INCLUDED */