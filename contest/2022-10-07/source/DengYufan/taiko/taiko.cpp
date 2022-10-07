#include <iostream>

using namespace std;

int n, m, a[8192];
bool b[8192] = {1};

void S(int x) {
  if (x > m) {
    cout << m << ' ';
    for (int i = 1; i <= n; i++) {
      cout << 0;
    }
    for (int i = 2; i <= m - n + 1; i++) {
      cout << (a[i] & 1);
    }
    exit(0);
  }
  a[x] = (a[x - 1] ^ (a[x - 1] & 1 << n - 1)) << 1;
  if (!b[a[x]]) {
    b[a[x]] = 1;
    S(x + 1);
    b[a[x]] = 0;
  }
  if (x <= m - n + 1 && !b[++a[x]]) {
    b[a[x]] = 1;
    S(x + 1);
    b[a[x]] = 0;
  }
}

int main() {
  freopen("taiko.in", "r", stdin);
  freopen("taiko.out", "w", stdout);
  cin >> n;
  m = 1 << n;
  S(2);
  return 0;
}
