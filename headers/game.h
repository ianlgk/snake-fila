#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "../headers/snake.h"

#define HEIGHT 23 // Define a altura do campo
#define WIDTH 89  // Define a largura do campo
#define WALL 177  // Define o caractere para desenhar o muro

/* Funções */

void walkToPosition();                                       // Adiciona uma cor no terminal em uma determinada posição
void erasePosition();                                        // Apaga a cor no terminal de uma determinada posição
int insertFood(int *x, int *y, TSnake *snake, TSnake *poop); // Printa uma comida aleatoria no campo e apenas se ela não estiver em cima de uma outra instancia
int gameExe(char *nickname);                                 // Executa o jogo da cobra
int getKey(int directions);                                  // Detecta qual tecla o usuário pressionou e descobre a direção
void changePositions(int *x, int *y, int directions);        // Altera a direção do movimento

/* Funções */

#endif /* GAME_H_INCLUDED */