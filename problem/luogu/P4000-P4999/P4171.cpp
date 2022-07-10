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

const int kN = 201;

int _, n, m, l[kN][2], r, b[kN], c, s[kN], t;
vector<int> e[kN];

int C(string x) { return (x[0] == 'h') * n + stoi(x.substr(1)); }
void D(int x) {
  l[x][0] = l[x][1] = ++r, b[x] = -1, s[++t] = x;
  for (int i : e[x]) {
    if (!b[i]) {
      D(i), l[x][1] = min(l[x][1], l[i][1]);
    } else if (!~b[i]) {
      l[x][1] = min(l[x][1], l[i][0]);
    }
  }
  if (l[x][0] == l[x][1]) {
    for (b[x] = ++c; s[t] != x; b[s[t--]] = c) {
    }
    --t;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> _; _--; ) {
    cin >> n >> m;
    for (int i = 1; i <= n * 2; ++i) {
      e[i].clear(), r = c = t = b[i] = 0;
    }
    for (int i = 1, x, y; i <= m; ++i) {
      string a, b, _a, _b;
      cin >> a >> b;
      _a = a, _a[0] = 'h' + 'm' - a[0], _b = b, _b[0] = 'h' + 'm' - b[0];
      e[C(_a)].push_back(C(b)), e[C(_b)].push_back(C(a));
    }
    for (int i = 1; i <= n * 2; ++i) {
      if (!b[i]) {
        D(i);
      }
    }
    bool f = 0;
    for (int i = 1; i <= n; ++i) {
      f |= b[i] == b[i + n];
    }
    cout << (f ? "BAD" : "GOOD") << '\n';
  }
  return 0;
}