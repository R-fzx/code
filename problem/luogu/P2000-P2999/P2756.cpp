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

const int kN = 101;

int n, m, p[kN], c, v[kN];
vector<int> e[kN];

bool F(int x, int f) {
  if (v[x] ^ f) {
    v[x] = f;
    for (int i : e[x]) {
      if (!p[i] || F(p[i], f)) {
        p[i] = x, p[x] = i;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m >> n;
  for (int x, y; (cin >> x >> y) && ~x && ~y;) {
    e[x].push_back(y);
  }
  for (int i = 1; i <= m; ++i) {
    c += F(i, i);
  }
  cout << c << '\n';
  for (int i = 1; i <= m; ++i) {
    if (p[i]) {
      cout << i << ' ' << p[i] << '\n';
    }
  }
  return 0;
}