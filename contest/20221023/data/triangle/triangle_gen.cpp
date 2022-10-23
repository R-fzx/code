#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

using namespace std;

const int kMaxN = 1e5 + 2, kV = 50;

long long a[kMaxN], b[kMaxN];

int Rand(int max) { return rand() % max; }

void Input(int i) {
  std::random_device rd;
  std::mt19937 g(rd());
  ofstream cout(to_string(i) + ".in");
  int n = 99998 + Rand(3), q = 99998 + Rand(3), m = 1;
  b[1] = 1;
  for (int i = 1; i <= n;) {
    a[i] = (i > b[m] ? a[i - 1] : 1) + (i > b[m] + 1 ? a[i - 2] : 0) + Rand(1e3);
    if (a[i] > 1e18) {
      b[++m] = i;
    } else {
      i++;
    }
  }
  b[m + 1] = n + 1;
  for (int i = 1; i <= m; i++) {
    shuffle(a + b[i], a + b[i + 1], g);
    cout << b[i + 1] - b[i] << ' ';
  }
  cout << '\n';
  cout << n << ' ' << q << '\n';
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= q; i++) {
    if (Rand(2)) {
      int x = Rand(m) + 1, z = Rand(b[x + 1] - b[x]), y = Rand(b[x + 1] - b[x] - z);
      cout << b[x] + y << ' ' << b[x] + y + z << '\n';
    } else {
      int z;
      if (Rand(2)) {
        z = Rand(n);
      } else {
        z = Rand(min(150, n));
      }
      int y = Rand(n - z) + 1;
      cout << y << ' ' << y + z << '\n';
    }
  }
}

int main() {
  srand((unsigned)time(0));
  for (int i = 6; i <= 9; i++) {
    Input(i);
  }
  return 0;
}