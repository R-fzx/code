#include <iostream>

using namespace std;

int t, x;

int main() {
  cin >> t;
  while (t--) {
    cin >> x;
    int i = 1, c = 0;
    for (; i * i < x; ++i) {
      c += x % i == 0;
    }
    cout << c * 2 + (i * i == x) << "\n";
  }
  return 0;
}