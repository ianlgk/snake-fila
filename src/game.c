#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

#include "../headers/game.h"
#include "../headers/snake.h"
#include "../headers/interface.h"
#include "../headers/customization.h"

int insertFood(int *x, int *y, TSnake *snake, TSnake *poop)
{
    int a = 0;
    TBody aux;
    srand(time(NULL));

    do
    {
        *y = (rand() % (HEIGHT - 3)) + 5;
        *x = (rand() % (WIDTH - 13)) + 36;
        for (int i = 0; i < snake->size; i++)
        {
            dequeue(snake, &aux);
            if (*x == aux.x && *y == aux.y)
            {
                a = 1;
                continue;
            }
            enqueue(aux, snake);
        }
        for (int i = 0; i < poop->size; i++)
        {
            dequeue(poop, &aux);
            if (*x == aux.x && *y == aux.y)
            {
                a = 1;
                continue;
            }
            enqueue(aux, poop);
        }
        a = 0;
    } while (a);

    gotoxy(0, 1);
    changeColorWhite();
    printf("x = %d, y = %d", *x, *y);
    gotoxy(*x, *y);
    int color = getRandomColor();
    printf("%c", 254);
    return color;
}

void walkToPosition(int x, int y)
{
    gotoxy(x, y);
    printf("%c", 219);
}

void erasePosition(int x, int y)
{
    gotoxy(x, y);
    changeColorBlack();
    printf("%c", 255);
}

int getKey(int directions)
{
    int tecla = getch();
    switch (tecla)
    {
    case 72: //^
        if (directions == 3)
            return directions;
        return 0;
        break;
    case 75: //<-
        if (directions == 2)
            return directions;
        return 1;
        break;
    case 77: //->
        if (directions == 1)
            return directions;
        return 2;
        break;
    case 80: //\/
        if (directions == 0)
            return directions;
        return 3;
        break;
    default:
        return directions;
        break;
    }
}

void changePositions(int *x, int *y, int directions)
{
    gotoxy(0, 0);
    changeColorWhite();
    printf("x = %d, y = %d d= %d", *x, *y, directions);
    switch (directions)
    {
    case 0:
        (*y)--;
        break;
    case 1:
        (*x)--;
        break;
    case 2:
        (*x)++;
        break;
    case 3:
        (*y)++;
        break;
    default:
        break;
    }
}

int gameExe(char *nickname)
{
    /* important variables */
    int x = (WIDTH / 2) + 34,
        y = (HEIGHT / 2) + 4,
        score = 0,
        speed = 250,
        direction = 0,
        color;

    TBody food, body, bodyAux, temp, poopAux;
    TSnake *snake = (TSnake *)malloc(sizeof(TSnake));
    TSnake *poopWall = (TSnake *)malloc(sizeof(TSnake));

    /* important variables */
    beginSnake(poopWall);
    beginSnake(snake);
    system("cls");
    createCobra(snake, x, y);

    system("cls");
    printBorders();
    printInfosGrid();
    printInfosInGame(nickname, score, snake->size);
    printGround();
    food.color = insertFood(&food.x, &food.y, snake, poopWall);
    food.code = snake->size;

    while (1)
    {
        gotoxy(3, 29);
        while (!kbhit())
        {
            //check collision
            if (y == 4 || y == 25 || x == 34 || x == (WIDTH + 24))
            {
                freeSnake(snake);
                freeSnake(poopWall);
                gameOver(&x, &y);
                return score;
            }

            Sleep(speed);

            //CheckFood

            if (x == food.x && y == food.y)
            {
                changeSnake(food, snake, poopWall);
                score += 10 * snake->size;
                food.color = insertFood(&food.x, &food.y, snake, poopWall);
                food.code = snake->size;
                printInfosInGame(nickname, score, snake->size);
                if (speed > 80)
                    speed -= 5;
            }

            dequeue(snake, &body);
            bodyAux = body;
            changePositions(&x, &y, direction);
            body.x = x;
            body.y = y;
            enqueue(body, snake);
            setColor(body.color);
            walkToPosition(x, y);

            for (int i = 0; i < poopWall->size; i++)
            {
                dequeue(poopWall, &poopAux);
                if (x == poopAux.x && y == poopAux.y)
                {
                    freeSnake(snake);
                    freeSnake(poopWall);
                    gameOver(&x, &y);
                    return score;
                }
                enqueue(poopAux, poopWall);
            }

            for (int i = 1; i < snake->size; i++)
            {
                dequeue(snake, &body);
                temp.x = body.x;
                temp.y = body.y;
                body.x = bodyAux.x;
                body.y = bodyAux.y;
                bodyAux.x = temp.x;
                bodyAux.y = temp.y;
                setColor(body.color);
                walkToPosition(body.x, body.y);
                enqueue(body, snake);
                //collision snake snake
                if (x == body.x && y == body.y)
                {
                    freeSnake(snake);
                    freeSnake(poopWall);
                    gameOver(&x, &y);
                    return score;
                }
            }
            erasePosition(bodyAux.x, bodyAux.y);
            gotoxy(3, 29);
        }

        direction = getKey(direction);
    }
}