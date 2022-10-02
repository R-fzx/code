#include <iostream>

using namespace std;

const long long kMaxN = 1e9 + 7;

long long n, num = 1, ans, a[10], temp;

int main() {
  freopen("sakura.in", "r", stdin);
  freopen("sakura.out", "w", stdout);
  cin >> n;
  if (n == 1 || n == 2 || n == 3 || n == 4) {
    cout << 1 + (n - 1) * 2;
  } else {
    num = 7;
    a[0] = 2;
    a[1] = 4;
    for (long long i = 0; i < n - 5; i++) {
      num += a[1];
      num %= kMaxN;
      temp = (a[0] + a[1]) % kMaxN;
      a[0] = a[1];
      a[1] = temp;
    }
    cout << (num + a[1]) % kMaxN;
  }
  return 0;
}