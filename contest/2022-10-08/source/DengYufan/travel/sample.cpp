#include <iostream>

using namespace std;

int main() {
  freopen("travel.in", "w", stdout);
  cout << 200 << ' ' << 861 << '\n';
  for (int i = 1; i <= 200; i++) {
    for (int j = i + 14; j <= 200; j++) {
      if (j % i) {
        continue;
      }
      cout << i << ' ' << j << '\n';
    }
  }
  return 0;
}
