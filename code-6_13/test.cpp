#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define Width 30
#define Height 30
#define MAX_LENGTH (Width * Height)

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

struct Point {
    int x;
    int y;
};

struct Snake {
    int length;
    int score;
    Point body[MAX_LENGTH];
    Direction direction;
};

struct Food {
    int x;
    int y;
};

Snake snake;
Food food;
bool gameOver;
int speed = 100;

#include <io.h>
#include <fcntl.h>

void SetConsoleProperties() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    //_setmode(_fileno(stdout), _O_U16TEXT);
    //SetConsoleOutputCP(CP_UTF8);
}


void Setup() {
    gameOver = false;
    snake.length = 1;
    snake.score = 0;
    snake.body[0].x = Width / 2;
    snake.body[0].y = Height / 2;
    snake.direction = RIGHT;
    food.x = rand() % Width;
    food.y = rand() % Height;
}

void Draw() {
    system("cls");
    for (int i = 0; i < Width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            if (j == 0)
                std::cout << "#";

            if (i == snake.body[0].y && j == snake.body[0].x)
                std::cout << "O";
            else if (i == food.y && j == food.x)
                std::cout << "F";
            else {
                bool printBody = false;
                for (int k = 1; k < snake.length; k++) {
                    if (snake.body[k].x == j && snake.body[k].y == i) {
                        std::cout << "o";
                        printBody = true;
                        break;
                    }
                }
                if (!printBody)
                    std::cout << " ";
            }

            if (j == Width - 1)
                std::cout << "#";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < Width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    std::cout << "Score: " << snake.score << std::endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            if (snake.direction != DOWN)
                snake.direction = UP;
            break;
        case 's':
            if (snake.direction != UP)
                snake.direction = DOWN;
            break;
        case 'a':
            if (snake.direction != RIGHT)
                snake.direction = LEFT;
            break;
        case 'd':
            if (snake.direction != LEFT)
                snake.direction = RIGHT;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    Point prev = snake.body[0];
    Point prev2;

    snake.body[0].x += (snake.direction == RIGHT) ? 1 : (snake.direction == LEFT) ? -1 : 0;
    snake.body[0].y += (snake.direction == DOWN) ? 1 : (snake.direction == UP) ? -1 : 0;

    for (int i = 1; i < snake.length; i++) {
        prev2 = snake.body[i];
        snake.body[i] = prev;
        prev = prev2;
    }

    if (snake.body[0].x >= Width)
        snake.body[0].x = 0;
    else if (snake.body[0].x < 0)
        snake.body[0].x = Width - 1;

    if (snake.body[0].y >= Height)
        snake.body[0].y = 0;
    else if (snake.body[0].y < 0)
        snake.body[0].y = Height - 1;

    for (int i = 1; i < snake.length; i++) {
        if (snake.body[i].x == snake.body[0].x && snake.body[i].y == snake.body[0].y) {
            gameOver = true;
            break;
        }
    }

    if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
        snake.score += 10;
        snake.length++;
        food.x = rand() % Width;
        food.y = rand() % Height;
        PlaySound(TEXT("eat.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}

int main() {


    SetConsoleProperties();

    Setup();

    PlaySound(TEXT("gameing.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(speed);
    }

    PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
    system("cls");
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your Score: " << snake.score << std::endl;

    return 0;
}
