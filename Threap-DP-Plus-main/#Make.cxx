#include <iostream>

#include "lib/mrrand.h"

using namespace std;

int main() {
  int n = rd(10);
  cout << n << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << rd(10) << ' ' << rd(10) << '\n';
  }
  return 0;
}