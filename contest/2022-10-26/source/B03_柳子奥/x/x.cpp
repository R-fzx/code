#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 5;

int n;
int x[kMaxN], y[kMaxN];

void sol1() {
  int ans = 0;
  int xx[kMaxN], yy[kMaxN];
  for (int i = 1; i < (1 << n); ++i) {
    int m = 0;
    for (int j = 1; j <= n; ++j) {
      if (i >> (j - 1) & 1) {
        xx[++m] = x[j], yy[++m] = y[j];
      }
    }
    for (int j = 1; j <= m; ++j) {
      for (int k = j + 1; k <= m; ++k) {
        if (abs(xx[j] - xx[k]) <= abs(yy[j] + yy[k])) {
          goto fuck;
        }
      }
    }
    ans = max(ans, m);
    fuck:;
  }
  cout << ans << endl;
}

void sol2() {
  sort(x + 1, x + 1 + n);
  int m = unique(x + 1, x + 1 + n) - (x + 1);
  cout << m << endl;
}

int main() {
  freopen("x.in", "r", stdin);
  freopen("x.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  if (n <= 20) {
    sol1();
  } else {
    sol2();
  }
  return 0;
}