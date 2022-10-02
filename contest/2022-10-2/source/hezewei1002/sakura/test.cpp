#include <iostream>

using namespace std;

const int kMaxN = 1e9 + 7;

int n, num = 1, ans;

int main() {
  freopen("sakura.in", "r", stdin);
  freopen("sakura.out", "w", stdout);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    num *= i;
  }
  for (int i = 2; i < 100000; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        if ((i / j * (j + 1) * i == (i + i / j * (j + 1)) * num)) {
          cout << i << ' ' << i / j * (j + 1) << endl;
          ans += 2;
          ans %= kMaxN;
        }
        j = i / j;
        if ((i / j * (j + 1) * i == (i + i / j * (j + 1)) * num)) {
          cout << i << ' ' << i / j * (j + 1) << endl;
          ans += 2;
          ans %= kMaxN;
        }
        j = i / j;
      }
    }
  }
  cout << (ans + 1) % kMaxN << endl;
  return 0;
}