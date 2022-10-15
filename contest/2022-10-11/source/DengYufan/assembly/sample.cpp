#include <ctime>
#include <iostream>

using namespace std;

const int kMaxN = 8, kMaxK = 8, kMaxV = 9999, kMaxL = 100;

int main() {
  freopen("assembly.in", "w", stdout);
  srand(time(0));
  cout << kMaxN << ' ' << kMaxK << ' ' << rand() % kMaxV + 1 << '\n';
  for (int i = 1; i <= kMaxN; i++) {
    cout << rand() % kMaxV + 1 << ' ' << rand() % kMaxL + 1 << '\n';
  }
}
