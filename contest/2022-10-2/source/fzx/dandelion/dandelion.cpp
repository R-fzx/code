#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 4e4 + 2, kB = 2e2 + 1;

int n, q, a[kN], _a[kN], m, b, nb, f[kB][kB], s[kB][kN], c[kN];

int L(int i) { return (i - 1) * b + 1; }
int R(int i) { return min(n, i * b); }
int I(int i) { return (i - 1) / b + 1; }

int main() {
  // freopen("dandelion.in", "r", stdin);
  // freopen("dandelion.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q, b = sqrt(n), nb = (n + b - 1) / b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], _a[i] = a[i];
  }
  sort(_a + 1, _a + n + 1), m = unique(_a + 1, _a + n + 1) - _a - 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(_a + 1, _a + m + 1, a[i]) - _a;
  }
  // cout << "-------------------------\n";
  for (int i = 1; i <= nb; ++i) {
    for (int j = 1; j <= m; ++j) {
      s[i][j] = s[i - 1][j];
    }
    for (int j = L(i); j <= R(i); ++j) {
      ++s[i][a[j]];
    }
    // for (int j = 1; j <= m; ++j) {
    //   cout << s[i][j] << ' ';
    // }
    // cout << '\n';
  }
  // cout << "-------------------------\n";
  for (int i = 1; i <= nb; ++i) {
    fill_n(c + 1, m, 0), f[i][i - 1] = f[i][i - 2] = m + 1;
    for (int j = i; j <= nb; ++j) {
      for (int k = L(j); k <= R(j); ++k) {
        ++c[a[k]];
      }
      f[i][j] = f[i][j - 1];
      for (int k = L(j); k <= R(j); ++k) {
        if (Pii{c[f[i][j]], -f[i][j]} < Pii{c[a[k]], -a[k]}) {
          f[i][j] = a[k];
        }
      }
      // cout << f[i][j] << ' ';
    }
    // cout << '\n';
  }
  // cout << "-------------------------\n";
  fill_n(c + 1, m, 0);
  for (int l, r, ans = 0; q--;) {
    cin >> l >> r;
    l = (l + ans - 1) % n + 1, r = (r + ans - 1) % n + 1, l > r && (swap(l, r), 0);
    ans = (I(r) - I(l) >= 2 ? f[I(l) + 1][I(r) - 1] : m + 1);
    // cout << l << ' ' << r << ' ' << ans << '\n';
    for (int i = l; i <= R(I(l)); ++i) {
      ++c[a[i]];
    }
    for (int i = L(I(r)); i <= r; ++i) {
      ++c[a[i]];
    }
    for (int i = l; i <= R(I(l)); ++i) {
      if (Pii{c[ans] + s[I(r) - 1][ans] - s[I(l)][ans], -ans} < Pii{c[a[i]] + s[I(r) - 1][a[i]] - s[I(l)][a[i]], -a[i]}) {
        ans = a[i];
      }
    }
    for (int i = L(I(r)); i <= r; ++i) {
      if (Pii{c[ans] + s[I(r) - 1][ans] - s[I(l)][ans], -ans} < Pii{c[a[i]] + s[I(r) - 1][a[i]] - s[I(l)][a[i]], -a[i]}) {
        ans = a[i];
      }
    }
    for (int i = l; i <= R(I(l)); ++i) {
      c[a[i]] = 0;
    }
    for (int i = L(I(r)); i <= r; ++i) {
      c[a[i]] = 0;
    }
    ans = _a[ans], cout << ans << '\n';
  }
  return 0;
}
/*
6 3
1 2 3 2 1 2
1 5 -> 1 5
3 6 -> 1 4
1 5
*/