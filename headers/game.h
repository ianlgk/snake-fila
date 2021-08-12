#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define HEIGHT 23                   // define a altura do campo
#define WIDTH 89                    // define a largura do campo
#define MURO 177                    // define o caractere para desenhar o muro

/* Functions */
void walkToPosition();
void erasePosition();
void insertFood();                  // printa uma comida aleatoria no campo
void printGround();                 // printa o campo para a cobra andar
int gameExe(char* nickname);        // executa o jogo da cobra
/* Functions */

# endif /* GAME_H_INCLUDED */
