#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#define LL long long

using namespace std;

LL n, ans = 1e18, a[2][200001];

LL Read() {
  LL x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

int main() {
  freopen("dark.in", "r", stdin);
  freopen("dark.out", "w", stdout);
  srand(time(0));
  n = Read();
  for (LL i = 1; i <= n; i++) {
    a[0][i] = Read(), a[1][i] = Read();
  }
  while (clock() <= 980) {
    LL x = rand() * rand() % n + 1, y = rand() * rand() % n + 1;
    if (x != y) {
      ans = min(ans, (a[0][x] - a[0][y]) * (a[0][x] - a[0][y]) + (a[1][x] - a[1][y]) * (a[1][x] - a[1][y]));
    }
  }
  cout << fixed << setprecision(3) << sqrt(ans) / 2.0;
  return 0;
}
