#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#define BORDER_HEIGHT 25 // limites laterais do aplicativo
#define BORDER_WIDTH 117 // limites superiores e inferiores do aplicativo

/* Functions */
void gotoxy(int x, int y);                                    // muda a posição da tela onde o cursor aponta
int mainMenu();                                               // printa o menu principal
void creditsMenu();                                           // printa o menu de créditos
void gameInformations();                                      // printa a primeira tela ao iniciar o programa
void printBorders();                                          // printa as bordas limitantes do programa
void printTitle();                                            // printa o título do jogo no mainMenu()
void printInfosGrid();                                        // durante o jogo, printa as bordas e labels de informações sobre o jogador
void printInfosInGame(char *nickname, int score, int nFoods); // printa as informações do jogo
void printGround();                                           // printa o campo para a cobra andar
void cleanGround(int *x, int *y);                             // limpa o campo que a cobra anda
void gameOver(int *x, int *y);                                // imprime tela de game over
/* Functions */

#endif /* INTERFACE_H_INCLUDED */