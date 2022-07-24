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

int t, n, c[15], ans;

void D(int);
void W(int x, int pc, int wc) { // pc张牌带pc-2组wc张同点牌
  for (int i = 1; i < 14; ++i) {
    if (c[i] >= pc) {
      c[i] -= pc;
      for (int j = 1; j < 15; ++j) {
        if (c[j] >= wc && (wc == 1 || j != 14)) {
          c[j] -= wc;
          if (pc - 3) {
            for (int k = 1; k < 15; ++k) {
              if (c[k] >= wc && (wc == 1 || k != 14)) {
                c[k] -= wc, D(x + 1), c[k] += wc;
              }
            }
          } else {
            D(x + 1);
          }
          c[j] += wc;
        }
      }
      c[i] += pc;
    }
  }
}
void S(int x, int pc, int l) { // 长度至少为l，每组牌pc张
  for (int i = 1, j = 0; i < 14; ++i) {
    if (c[i] < pc || i == 13) {
      for (int k = i - j; k < i; ++k) {
        c[k] += pc;
      }
      j = 0;
    } else {
      ++j, c[i] -= pc;
    }
    if (j >= l) {
      D(x + 1);
    }
  }
}
void D(int x) {
  if (x >= ans) {
    return;
  }
  W(x, 3, 1), W(x, 3, 2), W(x, 4, 1), W(x, 4, 2);
  S(x, 1, 5), S(x, 2, 3), S(x, 3, 2);
  for (int i = 1; i < 15; ++i) {
    x += !!c[i];
  }
  ans = min(ans, x);
}

int main() {
  // freopen("P2668_3.in", "r", stdin);
  // freopen("P2668.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t >> n; t--;) {
    fill(c + 1, c + 15, 0);
    for (int i = 1, x, y; i <= n; ++i) {
      cin >> x >> y;
      ++c[x ? x - 2 + (x == 1 || x == 2) * 13 : 14];
    }
    ans = 1e9, D(0);
    cout << ans << '\n';
  }
  return 0;
}
/*
3 4 5 6 7 8 9 10 J Q K A 2 W
0 3 2 2 2 0 0 0  3 0 1 0 0 1
*/