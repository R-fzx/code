#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

const int kMaxN = 4e4 + 5;

int n, m, kk, lst;
int a[kMaxN], b[kMaxN], cnt[kMaxN];

int main() {
  freopen("dandelion.in", "r", stdin);
  freopen("bf.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  kk = unique(b + 1, b + 1 + n) - (b + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b + 1, b + 1 + kk, a[i]) - b;
  }
  for (int i = 1, l, r; i <= m; ++i) {
    cin >> l >> r;
    l = (l + lst - 1) % n + 1, r = (r + lst - 1) % n + 1;
    if (l > r) swap(l, r);
    int mx = 0, num;
    for (int j = l; j <= r; ++j) {
      ++cnt[a[j]];
      if (cnt[a[j]] > mx) {
        mx = cnt[a[j]], num = a[j];
      } else if (cnt[a[j]] == mx && a[j] < num) {
        num = a[j];
      }
    }
    cout << (lst = b[num]) << endl;
    for (int j = l; j <= r; ++j) {
      cnt[a[j]] = 0;
    }
  }
  // cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}