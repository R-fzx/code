#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

int random(int n) {
  return 1ll * rand() * rand() * rand() % n + 1;
}

int main() {
  srand(114514);
  freopen("dandelion.in", "w", stdout);
  int n, m;
  n = 5000, m = 5000;
  cout << n << ' ' << m << endl;
  for (int i = 1; i <= n; ++i) {
    cout << random(1000000000) << ' ';
  }
  cout << endl;
  for (int i = 1; i <= m; ++i) {
    cout << random(n) << ' ' << random(n) << endl;
  }
  // cout << n << ' ' << m << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << rand() % 1000 + 1 << ' ';
  // }
  // cout << endl;
  // for (int i = 1; i <= m; ++i) {
  //   cout << rand() % n + 1 << ' ' << rand() % n + 1 << endl;
  // }
  return 0;
}