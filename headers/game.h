#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define HEIGHT 23                                   // define a altura do campo
#define WIDTH 89                                    // define a largura do campo
#define MURO 177                                    // define o caractere para desenhar o muro 

/* Functions */
void walkToPosition();                              // adiciona uma cor no terminal em uma determinada posição
void erasePosition();                               // apaga a cor no terminal de uma determinada posição
int insertFood(int *x,int *y);                      // printa uma comida aleatoria no campo
int gameExe(char* nickname);                        // executa o jogo da cobra
int getKey(int directions);                         // detecta qual tecla o usuário pressionou e descobre a direção
void changePositions(int *x,int *y,int directions); // altera a direção do movimento
/* Functions */

# endif /* GAME_H_INCLUDED */