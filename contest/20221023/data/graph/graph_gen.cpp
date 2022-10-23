#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

using namespace std;

const int kMaxN = 1e5 + 2, kV = 50;

long long a[kMaxN], b[kMaxN];

int Rand(int max) { return rand() % max; }

void Input(int i) {
  ofstream cout(to_string(i) + ".in");
  int n = 998 + Rand(3);
  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    cout << Rand(1e9) + 1 << ' ';
  }
}

int main() {
  srand((unsigned)time(0));
  for (int i = 4; i <= 9; i++) {
    Input(i);
  }
  return 0;
}