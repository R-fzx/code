#include <ctime>
#include <iostream>

using namespace std;

const int kN = 20, kL = 20;

int main() {
  freopen("codes.in", "w", stdout);
  srand(time(0));
  cout << kN << '\n';
  for (int i = 1; i <= kN; i++) {
    for (int j = 1; j <= min(i * 2, kN); j++) {
      cout << rand() % 2;
    }
    cout << '\n';
  }
  return 0;
}
