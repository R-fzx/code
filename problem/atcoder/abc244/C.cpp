#include <iostream>

using namespace std;

constexpr int N = 1005;

int n, a[N];

int main() {
  cin >> n;
  for (int i = 1, x;; i++) {
    if (i != 1) {
      cin >> x;
      a[x] = 1;
      if (!x) {
        break;
      }
    }
    for (int j = 1; j <= n * 2 + 1; j++) {
      if (!a[j]) {
        cout << j << endl;
        a[j] = 1;
        break;
      }
    }
  }
  return 0;
}