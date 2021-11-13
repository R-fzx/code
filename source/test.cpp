#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

#define STDOUT_H GetStdHandle(STD_OUTPUT_HANDLE)
void SetWindows(int h, int w) {
  char s[101];
  sprintf(s, "mode con lines=%d cols=%d", h, w), system(s);
}
void ClearWindows() { system("cls"); }
void SetCursor(int x, int y) {
  COORD p;
  p.X = x, p.Y = y, SetConsoleCursorPosition(STDOUT_H, p);
}
void SetColor(int c) {SetConsoleTextAttribute(STDOUT_H, c);}