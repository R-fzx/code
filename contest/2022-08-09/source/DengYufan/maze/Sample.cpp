#include <ctime>
#include <iostream>
#define LL long long

using namespace std;

const int kN = 20, kM = 20, kV = 1e4 + 1;

int main() {
  freopen("maze.in", "w", stdout);
  srand(time(0));
  cout << kN << ' ' << kM << ' ' << rand() * rand() % kV << '\n';
  for (int i = 1; i <= kN; i++) {
    for (int j = 1; j <= kM; j++) {
      cout << rand() * rand() % kV << ' ';
    }
    cout << '\n';
  }
  return 0;
}
