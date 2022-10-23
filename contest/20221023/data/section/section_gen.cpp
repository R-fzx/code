#include <algorithm>
#include <fstream>
#include <random>

using namespace std;

const int kMaxN = 1e6 + 1, kV = 50;

struct E {
  int i, o, l;
} e[kMaxN];
int a[kMaxN];

int Rand(int max) { return rand() % max; }

void Input(int i) {
  ofstream cout(to_string(i) + ".in");
  int n = 9998 + Rand(3), m = n / 4 + Rand(n / 4) - n / 8, q = 9998 + Rand(3);
  cout << n << ' ' << m << ' ' << q << '\n';
  for (int i = 1; i <= n; i++) {
    cout << Rand(1e5) + 1 << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= q / 5; i++) {
    e[i].l = e[i].i = Rand(n - m + 1) + 1, e[i].o = 1;
  }
  for (int i = q / 5 + 1; i <= q; i++) {
    e[i].i = e[Rand(q / 5) + 1].i;
    e[i].o = 2;
    e[i].l = Rand(n) + 1;
  }
  sort(e + 1, e + 1 + q, [](E x, E y) { return x.i < y.i; });
  for (int i = 1; i <= q; i++) {
    cout << e[i].o << ' ' << e[i].l << '\n';
  }
}

int main() {
  srand((unsigned)time(0));
  for (int i = 0; i <= 2; i++) {
    Input(i);
  }
  return 0;
}