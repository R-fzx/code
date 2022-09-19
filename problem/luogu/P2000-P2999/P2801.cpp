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

const int kN = 1e6 + 1, kB = 1e3 + 1;

int n, b, m, q, d[kN], l, r, v;
LL a[kN], t[kN];

bool C(int i, int j) { return a[i] < a[j]; }
int I(int x) { return (x + b - 1) / b; }
int L(int i) { return (i - 1) * b + 1; }
int R(int i) { return min(n, i * b); }
void Rs(int i) { sort(d + L(i), d + R(i) + 1, C); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q, b = sqrt(n * log2(n)), m = (n + b - 1) / b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], d[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    Rs(i);
  }
  for (char o; q--;) {
    cin >> o >> l >> r >> v;
    if (o == 'M') {
      for (int i = I(l) + 1; i < I(r); ++i) {
        t[i] += v;
      }
      if (I(l) == I(r)) {
        for (int i = l; i <= r; ++i) {
          a[i] += v;
        }
        Rs(I(l));
      } else {
        for (int i = l; i <= R(I(l)); ++i) {
          a[i] += v;
        }
        Rs(I(l));
        for (int i = L(I(r)); i <= r; ++i) {
          a[i] += v;
        }
        Rs(I(r));
      }
    } else {
      int ans = 0;
      for (int i = I(l) + 1; i < I(r); ++i) {
        int x = lower_bound(d + L(i), d + R(i) + 1, v - t[i], [](int i, LL j) { return a[i] < j; }) - d - L(i);
        ans += R(i) - L(i) + 1 - x;
      }
      if (I(l) == I(r)) {
        for (int i = l; i <= r; ++i) {
          ans += a[i] + t[I(l)] >= v;
        }
      } else {
        for (int i = l; i <= R(I(l)); ++i) {
          ans += a[i] + t[I(l)] >= v;
        }
        for (int i = L(I(r)); i <= r; ++i) {
          ans += a[i] + t[I(r)] >= v;
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}