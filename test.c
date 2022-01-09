#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
  char board[33][62];
  strcpy(&board[0][0], "\26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26\n");
  for (int i = 1; i < 30; i++) strcpy(&board[i][0], "\26                                                           \26\n");
  strcpy(&board[30][0], "\26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26 \26\nw:up s:down a:left d:right\n");
  int snake_num = 6, dir = 'a', snake[29 * 29] = {16, 30, 16, 32, 16, 34}, food[2] = {rand() % 29 + 1, (rand() % 29 + 1) * 2};
  for (int i = 0; i < snake_num; i += 2) board[snake[i]][snake[i + 1]] = '\26';
  board[food[0]][food[1]] = 1;
  while (memmove(snake + 2, snake, snake_num * sizeof(int))) {
    if (kbhit()) dir = getch();
    snake[1] = snake[3] + ((dir == 'a') ? -2 : (dir == 'd') ? 2
                                                            : 0);
    snake[0] = snake[2] + ((dir == 'w') ? -1 : (dir == 's') ? 1
                                                            : 0);
    if (board[snake[0]][snake[1]] == 1) {
      snake_num += 2;
      do {
        food[0] = rand() % 29 + 1;
        food[1] = (rand() % 29 + 1) * 2;
      } while (board[food[0]][food[1]] != ' ');
      board[food[0]][food[1]] = 1;
    } else if (board[snake[0]][snake[1]] == '\26')
      return printf("game over!\n");
    else
      board[snake[snake_num]][snake[snake_num + 1]] = ' ';
    board[snake[0]][snake[1]] = '\26';
    system("cls");
    sprintf(((char *)board) + 1949, "score: %d\n", (snake_num - 6) * 50);
    printf("%s", board);
    usleep(((500 - snake_num > 200) ? (500 - snake_num) : 200) * 1000);
  }
}