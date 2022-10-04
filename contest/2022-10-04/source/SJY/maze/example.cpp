#include <iostream>
#include <time.h>

using namespace std;

int t;
double l;
int r, c;

int main() {
  freopen("maze.in", "w", stdout);
  srand(time(NULL));
  t = rand() % 100;
  cout << t << '\n';
  while (t--) {
    l = (rand() % 100) * 1.0 / (rand() % 50);
    r = 5;
    c = 5;
    cout << l << ' ' << r << ' ' << c << '\n';
    int stx = 2, sty = 2;
    
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        if (i == 1 || j == 1) {
          cout << '#';
          continue;
        } else if (i == r || j == c) {
          cout << '#';
          continue;
        } else if (i == stx && j == sty) {
          cout << 'S';
          continue;
        } else if (i == r - 1 && j == c - 1) {
          cout << 'E';
          continue;
        }
        int t = rand() % 2;
        if (t == 1) {
          cout << ' ';
        } else {
          cout << '#';
        }
      }
      cout << '\n';
    }
    cout << '\n';
  }
}