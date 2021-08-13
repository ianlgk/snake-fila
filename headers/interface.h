#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#define BORDER_HEIGHT 25
#define BORDER_WIDTH 117

/* Functions */
void gotoxy(int x, int y);  // muda a posição da tela onde o cursor aponta
int mainMenu();             // printa o menu principal
void creditsMenu();         // printa o menu de créditos
void gameInformations();    // printa a primeira tela ao iniciar o programa
void printBorders();        // printa as bordas limitantes do programa
void printTitle();          // printa o título do jogo no mainMenu()
void printInfosGrid();      // durante o jogo, printa as bordas e labels de informações sobre o jogador
void printInfosInGame(char* nickname, int score, int nFoods); // printa as informações do jogo
/* Functions */

# endif /* INTERFACE_H_INCLUDED */