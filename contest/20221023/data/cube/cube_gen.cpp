#include <algorithm>
#include <fstream>
#include <random>

using namespace std;

const int kMaxN = 1e5 + 1, kV = 50;

int a[kMaxN];

int Rand(int max) { return rand() % max; }

void Input(int i) {
  ofstream cout(to_string(i) + ".in");
  int n = 48 + Rand(3);
  int p[3][2] = {{0}};
  for (int i = 0; i <= 2; i++) {
    p[i][0] = Rand(51) - 25, p[i][1] = Rand(51) - 25;
    if (p[i][0] > p[i][1]) {
      swap(p[i][0], p[i][1]);
    }
  }
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 2; k++) {
        cout << p[k][j] + (j ? 1 : -1) * Rand(26) << ' ';
      }
    }
    cout << endl;
  }
}

int main() {
  srand((unsigned)time(0));
  for (int i = 0; i <= 0; i++) {
    Input(i);
  }
  return 0;
}