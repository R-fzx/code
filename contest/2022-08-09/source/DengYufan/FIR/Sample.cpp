#include <ctime>
#include <iostream>
#define LL long long

using namespace std;

const int kN = 1000, kX = 10, kD = 1000;

int main() {
  freopen("FIR.in", "w", stdout);
  srand(time(0));
  cout << kN << ' ' << kX << '\n';
  for (int i = 1; i <= kN; i++) {
    cout << rand() % kD + 1 << ' ' << rand() % kD + 1 << '\n';
  }
  return 0;
}
