#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#define BORDER_HEIGHT 25 // Define os limites laterais do aplicativo
#define BORDER_WIDTH 117 // Define os limites superiores e inferiores do aplicativo

/* Funções */

void gotoxy(int x, int y);                                    // Muda a posição da tela onde o cursor aponta
int mainMenu();                                               // Printa o menu principal
void creditsMenu();                                           // Printa o menu de créditos
void gameInformations();                                      // Printa a primeira tela ao iniciar o programa
void printBorders();                                          // Printa as bordas limitantes do programa
void printTitle();                                            // Printa o título do jogo no mainMenu()
void printInfosGrid();                                        // Durante o jogo, printa as bordas e labels de informações sobre o jogador
void printInfosInGame(char *nickname, int score, int nFoods); // Printa as informações do jogo
void printGround();                                           // Printa o campo para a cobra andar
void cleanGround(int *x, int *y);                             // Limpa o campo que a cobra anda
void gameOver(int *x, int *y);                                // Imprime tela de game over

/* Funções */

#endif /* INTERFACE_H_INCLUDED */