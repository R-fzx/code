#include <ctime>
#include <iostream>
#define LL long long

using namespace std;

const int kN = 5000, kV = 100000000;

int main() {
  freopen("snowman.in", "w", stdout);
  srand(time(0));
  cout << kN << '\n';
  for (int i = 1; i <= kN; i++) {
    cout << rand() * rand() % kV + 1 << ' ';
  }
  return 0;
}
