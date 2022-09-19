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

const int kN = 1e5 + 1;

int n, m, b, d[kN];
LL a[kN], t[kN];

int I(int x) { return (x + b - 1) / b; }
int L(int i) { return (i - 1) * b + 1; }
int R(int i) { return min(n, i * b); }
void Rs(int i) {
  sort(d + L(i), d + R(i) + 1, [](int i, int j) { return a[i] < a[j]; });
}

int main() {
  // freopen("p6279.in", "r", stdin);
  // freopen("p6279.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n, b = sqrt(n * log2(n)), m = (n + b - 1) / b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], d[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    Rs(i);
  }
  for (int o, l, r, v, q = n; q--;) {
    cin >> o >> l >> r >> v;
    if (o) {
      LL ans = -1e18;
      if (I(l) == I(r)) {
        for (int i = l; i <= r; ++i) {
          if (a[i] + t[I(l)] < v) {
            ans = max(ans, a[i] + t[I(l)]);
          }
        }
      } else {
        for (int i = I(l) + 1; i < I(r); ++i) {
          auto x = lower_bound(d + L(i), d + R(i) + 1, v - t[i], [](int i, LL j) { return a[i] < j; });
          if (x > d + L(i)) {
            ans = max(ans, a[*(x - 1)] + t[i]);
          }
        }
        for (int i = l; i <= R(I(l)); ++i) {
          if (a[i] + t[I(l)] < v) {
            ans = max(ans, a[i] + t[I(l)]);
          }
        }
        for (int i = L(I(r)); i <= r; ++i) {
          if (a[i] + t[I(r)] < v) {
            ans = max(ans, a[i] + t[I(r)]);
          }
        }
      }
      cout << (ans == -1e18 ? -1 : ans) << '\n';
    } else {
      if (I(l) == I(r)) {
        for (int i = l; i <= r; ++i) {
          a[i] += v;
        }
        Rs(I(l));
      } else {
        for (int i = I(l) + 1; i < I(r); ++i) {
          t[i] += v;
        }
        for (int i = l; i <= R(I(l)); ++i) {
          a[i] += v;
        }
        Rs(I(l));
        for (int i = L(I(r)); i <= r; ++i) {
          a[i] += v;
        }
        Rs(I(r));
      }
    }

  }
  return 0;
}