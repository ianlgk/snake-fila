#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define height 20             // define a altura do campo
#define width 100           // define a largura do campo

/* Functions */
void gerarTela();//CRIAR
void changeColorRed();
void changeColorGreen();
void changeColorYellow();
void changeColorPurple();
void changeColorCyan();
void changeColorWhite();
void insertFood();
int getRandomColor();

/* Functions */
void printGround();                 // printa o campo para a cobra anda
int gameExe();                      // executa o jogo da cobra
/* Functions */
# endif /* INTERFACE_H_INCLUDED */
