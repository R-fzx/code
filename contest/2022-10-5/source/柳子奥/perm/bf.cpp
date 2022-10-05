#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#define pass 114514
#endif

#define int long long

using namespace std;

int n, ans;
int c[10];

void get(int n) {
  while (n) {
    ++c[n % 10], n /= 10;
  }
}

bool check(int x) {
  static int cc[10];
  memset(cc, 0, sizeof(cc));
  while (x) {
    ++cc[x % 10], x /= 10;
  }
  for (int i = 1; i <= 9; ++i) {
    if (cc[i] != c[i]) return 0;
  }
  return 1;
}

signed main() {
  freopen("perm.in", "r", stdin);
  freopen("bf.out", "w", stdout);
  cin >> n;
  get(n);
  for (int i = 1; i < n; ++i) {
    ans += check(i);
  }
  cout << ans << endl;
  return 0;
}