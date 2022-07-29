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

const int kN = 5e4 + 1;

random_device rd;
mt19937 rnd(rd());
int n, m, s, a[kN], l[kN], t;
vector<Pii> e[kN];
bool v[kN];

void D(int x, int f, int w) {
  for (Pii &i : e[x]) {
    if (i.first != f) {
      D(i.first, x, w);
    }
  }
  t = 0;
  for (Pii &i : e[x]) {
    if (i.first != f) {
      if (a[i.first] + i.second >= w) {
        ++s;
      } else {
        l[++t] = a[i.first] + i.second;
      }
    }
  }
  fill(v + 1, v + t + 1, 0);
  sort(l + 1, l + t + 1);
  for (int i = 1; i <= t; ++i) {
    if (!v[i]) {
      auto p = upper_bound(l + i + 1, l + t + 1, w - l[i] - 1) - l;
      for (; p <= t && v[p]; ++p) {
      }
      if (p <= t) {
        v[i] = 1, v[p] = 1, ++s;
      }
    }
  }
  a[x] = 0;
  for (int i = t; i >= 1; --i) {
    if (!v[i]) {
      a[x] = l[i];
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y, w; i < n; ++i) {
    cin >> x >> y >> w;
    e[x].emplace_back(y, w), e[y].emplace_back(x, w);
  }
  int l = 0, r = 1e9;
  while (l < r) {
    int m = l + r + 1 >> 1;
    s = 0, D(uniform_int_distribution<int>(1, n)(rnd), 0, m);
    if (s >= ::m) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l;
  return 0;
}