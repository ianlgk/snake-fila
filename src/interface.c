#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "../headers/game.h"
#include "../headers/snake.h"
#include "../headers/interface.h"
#include "../headers/customization.h"

void gameInformations()
{
    system("cls");
    printBorders();
    gotoxy(51, 14);
    changeColorYellow();
    printf("Jogo Snake em C\n\n");
    gotoxy(52, 15);
    changeColorRed();
    printf("UFOP");
    gotoxy(57, 15);
    changeColorWhite();
    printf("- AEDS I");
    gotoxy(3, 28);
    Sleep(3000);
}

int mainMenu()
{
    int key, x, y;
    x = 27;
    y = 20;

    system("cls");
    printBorders();
    printTitle();
    gotoxy(28, 20);
    printf(" JOGAR");
    gotoxy(54, 20);
    printf(" CREDITOS");
    gotoxy(83, 20);
    printf(" SAIR");

    do
    {
        gotoxy(x, y);
        changeColorGreen();
        printf("%c", 175);
        changeColorWhite();
        gotoxy(3, 28);
        key = getch();
        switch (key)
        {
        case 13: // Quando usuário pressiona enter
            switch (x)
            { // Retorna a opção selecionada
            case 27:
                gotoxy(27, 20);
                printf("       ");
                gotoxy(83, 20);
                printf("      ");
                gotoxy(43, 20);
                changeColorGreen();
                printf("%c", 175);
                changeColorWhite();
                return 1;
                break;
            case 53:
                return 2;
                break;
            case 82:
                return 3;
                break;
            default:
                break;
            }
            break;
        case 75: // Quando o usuário digita a tecla de seta para esquerda (<-)
            if (x != 27)
            {
                if (x == 82)
                {
                    gotoxy(x, y);
                    printf("  ");
                    x -= 29;
                }
                else
                {
                    gotoxy(x, y);
                    printf("  ");
                    x -= 26;
                }
            }
            else
            {
                // Não faz nada, pois já está na borda
            }
            break;
        case 77: // Quando o usuário digita a tecla de seta para direita (->)
            if (x != 82)
            {
                if (x == 27)
                {
                    gotoxy(x, y);
                    printf("  ");
                    x += 26;
                }
                else
                {
                    gotoxy(x, y);
                    printf("  ");
                    x += 29;
                }
            }
            else
            {
                // Não faz nada, pois já está na borda
            }
            break;
        default:
            break;
        }
    } while (key != 13);

    printf("\n\n");
}

void printTitle()
{
    // Bordas do título
    changeColorRed();
    for (int i = 22; i < 96; i++)
    {
        gotoxy(i, 7);
        printf("%c", 219);
    }

    for (int i = 7; i < 18; i++)
    {
        gotoxy(22, i);
        printf("%c", 219);
        gotoxy(96 - 1, i);
        printf("%c\n", 219);
    }

    for (int i = 22; i < 96; i++)
    {
        gotoxy(i, 17);
        printf("%c", 219);
    }

    // Preencher o background do título
    changeColorCyan();
    for (int i = 23; i < 95; i++)
    {
        for (int j = 8; j < 17; j++)
        {
            gotoxy(i, j);
            printf("%c", 219);
        }
    }

    // Escrever SNAKE
    changeColorWhite();

    // S
    gotoxy(26, 14);
    printf("%c", 219);
    gotoxy(27, 15);
    printf("%c", 219);
    gotoxy(28, 15);
    printf("%c", 219);
    gotoxy(29, 15);
    printf("%c", 219);
    gotoxy(30, 14);
    printf("%c", 219);
    gotoxy(30, 13);
    printf("%c", 219);
    gotoxy(30, 14);
    printf("%c", 219);
    gotoxy(29, 12);
    printf("%c", 219);
    gotoxy(28, 12);
    printf("%c", 219);
    gotoxy(27, 12);
    printf("%c", 219);
    gotoxy(26, 11);
    printf("%c", 219);
    gotoxy(26, 10);
    printf("%c", 219);
    gotoxy(27, 9);
    printf("%c", 219);
    gotoxy(28, 9);
    printf("%c", 219);
    gotoxy(29, 9);
    printf("%c", 219);
    gotoxy(30, 10);
    printf("%c", 219);
    // S

    // N
    gotoxy(33, 9);
    printf("%c", 219);
    gotoxy(33, 10);
    printf("%c", 219);
    gotoxy(33, 11);
    printf("%c", 219);
    gotoxy(33, 12);
    printf("%c", 219);
    gotoxy(33, 13);
    printf("%c", 219);
    gotoxy(33, 14);
    printf("%c", 219);
    gotoxy(33, 15);
    printf("%c", 219);
    gotoxy(34, 10);
    printf("%c", 219);
    gotoxy(35, 11);
    printf("%c", 219);
    gotoxy(36, 12);
    printf("%c", 219);
    gotoxy(37, 13);
    printf("%c", 219);
    gotoxy(38, 14);
    printf("%c", 219);
    gotoxy(39, 15);
    printf("%c", 219);
    gotoxy(39, 14);
    printf("%c", 219);
    gotoxy(39, 13);
    printf("%c", 219);
    gotoxy(39, 12);
    printf("%c", 219);
    gotoxy(39, 11);
    printf("%c", 219);
    gotoxy(39, 10);
    printf("%c", 219);
    gotoxy(39, 9);
    printf("%c", 219);
    // N

    // A
    gotoxy(42, 15);
    printf("%c", 219);
    gotoxy(42, 14);
    printf("%c", 219);
    gotoxy(42, 13);
    printf("%c", 219);
    gotoxy(43, 13);
    printf("%c", 219);
    gotoxy(44, 13);
    printf("%c", 219);
    gotoxy(45, 13);
    printf("%c", 219);
    gotoxy(46, 13);
    printf("%c", 219);
    gotoxy(47, 13);
    printf("%c", 219);
    gotoxy(48, 13);
    printf("%c", 219);
    gotoxy(48, 15);
    printf("%c", 219);
    gotoxy(48, 14);
    printf("%c", 219);
    gotoxy(48, 12);
    printf("%c", 219);
    gotoxy(42, 12);
    printf("%c", 219);
    gotoxy(47, 11);
    printf("%c", 219);
    gotoxy(43, 11);
    printf("%c", 219);
    gotoxy(46, 10);
    printf("%c", 219);
    gotoxy(44, 10);
    printf("%c", 219);
    gotoxy(45, 9);
    printf("%c", 219);
    // A
    // K
    gotoxy(51, 9);
    printf("%c", 219);
    gotoxy(51, 10);
    printf("%c", 219);
    gotoxy(51, 11);
    printf("%c", 219);
    gotoxy(51, 12);
    printf("%c", 219);
    gotoxy(51, 13);
    printf("%c", 219);
    gotoxy(51, 14);
    printf("%c", 219);
    gotoxy(51, 15);
    printf("%c", 219);
    gotoxy(52, 12);
    printf("%c", 219);
    gotoxy(53, 12);
    printf("%c", 219);
    gotoxy(54, 11);
    printf("%c", 219);
    gotoxy(55, 10);
    printf("%c", 219);
    gotoxy(56, 9);
    printf("%c", 219);
    gotoxy(54, 13);
    printf("%c", 219);
    gotoxy(55, 14);
    printf("%c", 219);
    gotoxy(56, 15);
    printf("%c", 219);
    // K

    // E
    gotoxy(59, 15);
    printf("%c", 219);
    gotoxy(59, 14);
    printf("%c", 219);
    gotoxy(59, 13);
    printf("%c", 219);
    gotoxy(59, 12);
    printf("%c", 219);
    gotoxy(59, 11);
    printf("%c", 219);
    gotoxy(59, 10);
    printf("%c", 219);
    gotoxy(59, 9);
    printf("%c", 219);
    gotoxy(60, 15);
    printf("%c", 219);
    gotoxy(61, 15);
    printf("%c", 219);
    gotoxy(62, 15);
    printf("%c", 219);
    gotoxy(63, 15);
    printf("%c", 219);
    gotoxy(64, 15);
    printf("%c", 219);
    gotoxy(60, 9);
    printf("%c", 219);
    gotoxy(61, 9);
    printf("%c", 219);
    gotoxy(62, 9);
    printf("%c", 219);
    gotoxy(63, 9);
    printf("%c", 219);
    gotoxy(64, 9);
    printf("%c", 219);
    gotoxy(60, 12);
    printf("%c", 219);
    gotoxy(61, 12);
    printf("%c", 219);
    gotoxy(62, 12);
    printf("%c", 219);
    gotoxy(63, 12);
    printf("%c", 219);
    // E

    // -
    gotoxy(71, 12);
    printf("%c", 219);
    gotoxy(72, 12);
    printf("%c", 219);
    gotoxy(73, 12);
    printf("%c", 219);
    gotoxy(74, 12);
    printf("%c", 219);
    gotoxy(75, 12);
    printf("%c", 219);
    gotoxy(76, 12);
    printf("%c", 219);
    gotoxy(77, 12);
    printf("%c", 219);
    // -

    // C
    gotoxy(86, 15);
    printf("%c", 219);
    gotoxy(87, 15);
    printf("%c", 219);
    gotoxy(88, 15);
    printf("%c", 219);
    gotoxy(89, 15);
    printf("%c", 219);
    gotoxy(90, 15);
    printf("%c", 219);
    gotoxy(85, 14);
    printf("%c", 219);
    gotoxy(84, 13);
    printf("%c", 219);
    gotoxy(84, 12);
    printf("%c", 219);
    gotoxy(84, 11);
    printf("%c", 219);
    gotoxy(85, 10);
    printf("%c", 219);
    gotoxy(86, 9);
    printf("%c", 219);
    gotoxy(87, 9);
    printf("%c", 219);
    gotoxy(88, 9);
    printf("%c", 219);
    gotoxy(89, 9);
    printf("%c", 219);
    gotoxy(90, 9);
    printf("%c", 219);
    gotoxy(91, 14);
    printf("%c", 219);
    gotoxy(91, 10);
    printf("%c", 219);
    // C
}

void creditsMenu()
{
    system("cls");
    printBorders();
    gotoxy(34, 9);
    changeColorRed();
    printf("UFOP");
    gotoxy(39, 9);
    changeColorWhite();
    printf("- Algoritmos e Estruturas de Dados I / 2021");
    gotoxy(49, 11);
    printf("Desenvolvido por:");
    gotoxy(38, 13);
    printf("20.1 | S.I - Ian Langkammer Batista");
    gotoxy(38, 14);
    printf("20.1 | S.I - Leonardo Moreira Sepulveda");
    gotoxy(38, 15);
    printf("20.1 | S.I - Rafael Caetano Texeira");
    gotoxy(38, 16);
    printf("20.1 | S.I - Victor Gabriel Siqueira Moura");
    gotoxy(38, 17);
    printf("18.1 | E.P - Paulo Cesar de Freitas Lagares");
    gotoxy(36, 19);
    changeColorCyan();
    printf("Repositorio:");
    gotoxy(49, 19);
    changeColorWhite();
    printf("github.com/LeoMoreiraS/snake-snake");
    gotoxy(3, 28);
    Sleep(5000);
}

void printBorders()
{
    changeColorWhite();

    for (int i = 3; i < BORDER_WIDTH; i++)
    {
        gotoxy(i, 2);
        if (i == 3)
            printf("%c", 201);
        else if (i + 1 == BORDER_WIDTH)
            printf("%c", 187);
        else
            printf("%c", 205);
    }

    for (int i = 3; i < BORDER_HEIGHT + 3; i++)
    {
        gotoxy(3, i);
        printf("%c", 186);
        gotoxy(BORDER_WIDTH - 1, i);
        printf("%c\n", 186);
    }

    for (int i = 3; i < BORDER_WIDTH; i++)
    {
        gotoxy(i, BORDER_HEIGHT + 2);
        if (i == 3)
            printf("%c", 200);
        else if (i + 1 == BORDER_WIDTH)
            printf("%c", 188);
        else
            printf("%c", 205);
    }
}

void printInfosGrid()
{
    gotoxy(6, 4);
    printf("%c", 201);

    // Printa limite superior
    for (int i = 7; i < 31; i++)
    {
        gotoxy(i, 4);
        printf("%c", 205);
    }

    gotoxy(31, 4);
    printf("%c", 187);
    gotoxy(6, 25);
    printf("%c", 200);

    // Printa os limites laterais
    for (int i = 5; i < 25; i++)
    {
        // Printa as bordas com saídas laterais
        switch (i)
        {
        case 8:
            gotoxy(6, i);
            printf("%c", 204);
            gotoxy(31, i);
            printf("%c", 185);
            break;
        case 12:
            gotoxy(6, i);
            printf("%c", 204);
            gotoxy(31, i);
            printf("%c", 185);
            break;
        case 16:
            gotoxy(6, i);
            printf("%c", 204);
            gotoxy(31, i);
            printf("%c", 185);
            break;
        default:
            gotoxy(6, i);
            printf("%c", 186);
            gotoxy(31, i);
            printf("%c", 186);
            break;
        }
    }

    gotoxy(31, 25);
    printf("%c", 188);

    // Printa o limite inferior
    for (int i = 7; i < 31; i++)
    {
        gotoxy(i, 25);
        printf("%c", 205);
    }

    // Printa divisão de informações
    for (int i = 7; i < 31; i++)
    {
        gotoxy(i, 8);
        printf("%c", 205);
    }

    for (int i = 7; i < 31; i++)
    {
        gotoxy(i, 12);
        printf("%c", 205);
    }

    for (int i = 7; i < 31; i++)
    {
        gotoxy(i, 16);
        printf("%c", 205);
    }

    for (int i = 7; i < 31; i++)
    {
        gotoxy(i, 23);
        printf("%c", 205);
    }

    // Printa as labels
    gotoxy(8, 24);
    changeColorGreen();
    printf("Thanks for playing  :)");
    gotoxy(13, 6);
    changeColorRed();
    printf("UFOP");
    changeColorWhite();
    gotoxy(17, 6);
    printf(" - AEDS I");
    gotoxy(8, 10);
    printf("Player: ");
    gotoxy(8, 14);
    printf(" SCORE ");
    gotoxy(14, 19);
    printf("SNAKE SIZE");
}

void printInfosInGame(char *nickname, int score, int snakeSize)
{
    changeColorWhite();
    gotoxy(17, 10);
    printf("%s", nickname);

    gotoxy(17, 14);
    printf("%d", score);

    gotoxy(17, 20);
    if (snakeSize >= 1000)
        printf("%d", snakeSize);
    else if (snakeSize >= 100)
        printf("0%d", snakeSize);
    else if (snakeSize >= 10)
        printf("00%d", snakeSize);
    else
        printf("000%d", snakeSize);
}

void printGround()
{
    changeColorRed();
    // Printa o limite superior do campo
    for (int i = 34; i < WIDTH + 25; i++)
    {
        gotoxy(i, 4);
        printf("%c", WALL);
    }

    // Printa os limites laterais do campo
    for (int i = 5; i < HEIGHT + 2; i++)
    {
        gotoxy(34, i);
        printf("%c", WALL);
        gotoxy(24 + WIDTH, i);
        printf("%c", WALL);
    }

    // Printa o limite inferior do campo
    for (int i = 34; i < WIDTH + 25; i++)
    {
        gotoxy(i, 25);
        printf("%c", WALL);
    }
}

void cleanGround(int *x, int *y)
{
    changeColorRed();
    gotoxy(*x, *y);
    printf("%c", WALL);

    changeColorBlack();
    for (int i = 35; i < WIDTH + 24; i++)
    {
        for (int j = 5; j < HEIGHT + 2; j++)
        {
            gotoxy(i, j);
            printf("%c", 255);
        }
    }

    changeColorWhite();
}

void gameOver(int *x, int *y)
{
    cleanGround(x, y);
    gotoxy(70, 14);
    changeColorRed();
    printf("GAME OVER");
    changeColorWhite();
    gotoxy(59, 18);
    printf("Veja a sua pontuacao a esquerda!");
    Sleep(1500);
    gotoxy(54, 22);
    system("pause");
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}