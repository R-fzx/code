#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...)
#endif

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

int read() {
  int x = 0, f = 0; char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}

int random(int n) {
  return 1ll * rand() * rand() * rand() % n + 1;
}
int random(int l, int r) {
  return random(r - l + 1) + (l - 1);
}

int main() {
  srand(time(NULL));
  freopen("guard.in", "w", stdout);
  int n = 200, l = random(0, n), k = random(0, 2000);
  cout << n << ' ' << l << ' ' << k << endl;
  for (int i = 1; i <= n; ++i) {
    cout << random(0, 100) << ' ';
  }
  cout << endl;
  for (int i = 1; i <= n; ++i) {
    int op = rand() % 2;
    // if (op) cout << -1 << ' ';
    cout << random(0, 1000) << ' ';
  }
  return 0;
}