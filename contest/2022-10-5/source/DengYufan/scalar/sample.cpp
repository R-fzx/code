#include <ctime>
#include <iostream>

using namespace std;

const int kMaxN = 10, kMaxV = 10;

int main() {
  freopen("scalar.in", "w", stdout);
  srand(time(0));
  cout << kMaxN << '\n';
  for (int i = 1; i <= kMaxN; i++) {
    cout << rand() * rand() % (kMaxV * 2 + 1) - kMaxV << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= kMaxN; i++) {
    cout << rand() * rand() % (kMaxV * 2 + 1) - kMaxV << ' ';
  }
  return 0;
}
