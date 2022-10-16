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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 501, kD[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m, sx, sy, tx, ty, d[kN * kN];
char a[kN][kN];
priority_queue<Pii, vector<Pii>, greater<Pii>> q;
vector<Pii> e[kN * kN];

int E(int x, int y) { return (x - 1) * m + y; }
void R(int x, int _d) {
  if (_d < d[x]) {
    d[x] = _d, q.emplace(_d, x);
  }
}

int main() {
  RF("portal");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] + 1;
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 'C') {
        sx = i, sy = j;
      } else if (a[i][j] == 'F') {
        tx = i, ty = j;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] != '#') {
        int mn = 1e9, x[4], y[4], c[4];
        for (int k = 0; k < 4; ++k) {
          e[E(i, j)].emplace_back(E(i + kD[k][0], j + kD[k][1]), 1);
          for (x[k] = i, y[k] = j, c[k] = 0; a[x[k] + kD[k][0]][y[k] + kD[k][1]] != '#'; x[k] += kD[k][0], y[k] += kD[k][1], ++c[k]) {
          }
          mn = min(mn, c[k]);
        }
        for (int k = 0; k < 4; ++k) {
          e[E(i, j)].emplace_back(E(x[k], y[k]), mn + 1);
        }
      }
    }
  }
  fill(d + E(1, 1), d + E(n, m) + 1, 1e9);
  for (R(E(sx, sy), 0); !q.empty(); ) {
    int x = q.top().second, v = q.top().first;
    q.pop();
    if (v == d[x]) {
      for (Pii i : e[x]) {
        R(i.first, v + i.second);
      }
    }
  }
  if (d[E(tx, ty)] == 1e9) {
    cout << "nemoguce"; 
  } else {
    cout << d[E(tx, ty)];
  }
  return 0;
}