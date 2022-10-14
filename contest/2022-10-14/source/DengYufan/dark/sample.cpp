#include <ctime>
#include <iostream>

using namespace std;

const int kN = 2e5, kV = 1e6;
int x, y;

int main() {
  freopen("dark.in", "w", stdout);
  srand(time(0));
  cout << kN << '\n';
  x = rand() * rand() % kN + 1, y = rand() * rand() % kN + 1;
  if (x > y) {
    swap(x, y);
  }
  if (x == y) {
    y++;
  }
  for (int i = 1; i < x; i++) {
    cout << rand() * rand() % (kV + 1) << ' ' << rand() * rand() % (kV + 1) << '\n';
  }
  cout << 0 << ' ' << 0 << '\n';
  for (int i = x + 1; i < y; i++) {
    cout << rand() * rand() % (kV + 1) << ' ' << rand() * rand() % (kV + 1) << '\n';
  }
  cout << 0 << ' ' << 0 << '\n';
  for (int i = y + 1; i <= kN; i++) {
    cout << rand() * rand() % (kV + 1) << ' ' << rand() * rand() % (kV + 1) << '\n';
  }
  return 0;
}
