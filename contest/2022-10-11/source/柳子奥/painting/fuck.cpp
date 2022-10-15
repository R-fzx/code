#include <bits/stdc++.h>

using namespace std;

int f[2005];

int main() {
  f[0] = 1;
  for (int i = 1; i <= 1; ++i) {
    for (int j = i; j; --j) {
      f[j] = f[j] * j + f[j - 1] * (2 - j + 1);
    }
    f[0] = 0;
  }
  cout << f[1] << endl;
  return 0;
}