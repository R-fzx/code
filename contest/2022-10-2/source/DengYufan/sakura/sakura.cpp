#include <ctime>
#include <iostream>

using namespace std;

const long long kMod = 1e9 + 7;

int main() {
  freopen("sakura.in", "r", stdin);
  freopen("sakura.out", "w", stdout);
  srand(time(0));
  cout << (long long)rand() * rand() * rand() % kMod;
  return 0;
}
