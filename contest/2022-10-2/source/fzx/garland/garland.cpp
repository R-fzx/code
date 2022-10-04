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

const int kN = 501;

int n;
LL v[kN][kN], l[kN][kN], r[kN][kN], b[kN][kN], s;
vector<Pii> p;
vector<int> d;

int main() {
  freopen("garland.in", "r", stdin), freopen("garland.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> v[i][j];
      if (i >= j) {
        v[j][i] += v[i][j];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> l[i][j];
      if (i > j) {
        l[j][i] = max(l[i][j], l[j][i]) << 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> r[i][j];
      if (i > j) {
        r[j][i] = min(r[i][j], r[j][i]) << 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      b[i][j] = r[i][j], s += b[i][j];
      p.emplace_back(i, j);
    }
  }
  sort(p.begin(), p.end(), [](Pii i, Pii j) { return v[i.first][i.second] < v[j.first][j.second]; });
  int _i = 0, _j = 0;
  for (Pii &i : p) {
    LL x = min(s, r[i.first][i.second] - l[i.first][i.second]);
    s -= x, b[i.first][i.second] -= x;
    if (!s) {
      if ((b[i.first][i.second] & 1) && i.first != i.second) {
        tie(_i, _j) = i;
      }
      break;
    }
  }
  s = 0;
  if (_i) {
    LL _s;
    if (b[_i][_j] < r[_i][_j]) {
      _s = 0;
      for (int i = 1; i <= n; ++i) {
        if (b[i][i] != l[i][i]) {
          d.push_back(i);
        }
      }
      sort(d.begin(), d.end(), [](int i, int j) { return v[i][i] < v[j][j]; });
      ++b[_i][_j], --b[d.front()][d.front()];
      for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
          _s += b[i][j] * v[i][j];
        }
      }
      s = max(s, _s);
      --b[_i][_j], ++b[d.front()][d.front()], d.clear();
    }
    if (b[_i][_j] > l[_i][_j]) {
      _s = 0;
      for (int i = 1; i <= n; ++i) {
        if (b[i][i] != r[i][i]) {
          d.push_back(i);
        }
      }
      sort(d.begin(), d.end(), [](int i, int j) { return v[i][i] > v[j][j]; });
      --b[_i][_j], ++b[d.front()][d.front()];
      for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
          _s += b[i][j] * v[i][j];
        }
      }
      s = max(s, _s);
      ++b[_i][_j], --b[d.front()][d.front()], d.clear();
    }
  } else {
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        s += b[i][j] * v[i][j];
      }
    }
  }
  cout << s / 2;
  return 0;
}
/*
5
0 3 2 1 2
0 0 3 0 2
1 2 1 0 3
0 0 3 1 1
0 0 0 3 3
-8 -1 -5 -7 -9
-9 -10 -9 -8 -10
-8 -3 -10 -8 -4
-8 -1 -3 -4 -2
-8 -6 -7 -6 -2
6 7 3 2 4
8 4 2 1 10
0 5 -2 10 4
4 7 8 9 5
4 1 7 4 6

*/