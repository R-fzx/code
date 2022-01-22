#include <iostream>

using namespace std;
using LL = long long;

LL t, x;

int main() {
  cin >> t;
  while (t--) {
    cin >> x;
    for (; x % 2 == 0; x >>= 1) {
    }
    cout << (x > 3) << endl;
  }
  return 0;
}