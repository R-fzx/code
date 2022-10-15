#include <ctime>
#include <iostream>

using namespace std;

const int kMaxN = 200, kMaxM = 50000, kMaxV = 1e9;
int f[kMaxN + 1];

int GetRoot(int x) {
  return f[x] == x ? x : f[x] = GetRoot(f[x]);
}

int main() {
  freopen("road.in", "w", stdout);
  srand(time(0));
  cout << kMaxN << ' ' << kMaxM << ' ' << rand() * rand() % (kMaxV + 1) << ' ' << rand() * rand() % (kMaxV + 1) << '\n';
  for (int i = 1; i <= kMaxN; i++) {
    f[i] = i;
  }
  for (int i = 1; i < kMaxN; i++) {
    int x = rand() % kMaxN + 1, y = rand() % kMaxN + 1;
    while (GetRoot(x) == GetRoot(y)) {
      x = rand() % kMaxN + 1, y = rand() % kMaxN + 1;
    }
    cout << x << ' ' << y << ' ' << rand() * rand() % (kMaxV + 1) << ' ' << rand() * rand() % (kMaxV + 1) << '\n';
  }
  for (int i = kMaxN; i <= kMaxM; i++) {
    cout << rand() % kMaxN + 1 << ' ' << rand() % kMaxN + 1 << ' ' << rand() * rand() % (kMaxV + 1) << ' ' << rand() * rand() % (kMaxV + 1) << '\n';
  }
}
