#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 17, kM = 1e4 + 1;

int n, m, a[kN][kM], d[kN], v[kN], t;
vector<int> e[kN];

bool F(int x, int k) {
  if (x == n + 1) {
    // for (int i = 1; i <= n; ++i) {
    //   cerr << d[i] << " ";
    // }
    // cerr << endl;
    bool f = 1;
    for (int i = 1; i < m; ++i) {
      f &= abs(a[d[n]][i] - a[d[1]][i + 1]) >= k;
    }
    return f;
  }
  for (int i : e[d[x - 1]]) {
    if (v[i] ^ t) {
      v[i] = t, d[x] = i;
      if (F(x + 1, k)) {
        return 1;
      }
      v[i] = 0;
    }
  }
  return 0;
}
bool C(int x) {
  for (int i = 1; i <= n; ++i) {
    e[i].clear();
    for (int j = 1; j <= n; ++j) {
      bool f = 1;
      for (int k = 1; k <= m; ++k) {
        f &= abs(a[i][k] - a[j][k]) >= x;
      }
      if (f) {
        e[i].push_back(j);
      }
    }
    // cerr << "#" << i << ":";
    // for (int j : e[i]) {
    //   cerr << " " << j;
    // }
    // cerr << endl;
  }
  ++t;
  return F(1, x);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    e[0].push_back(i);
  }
  int l = 0, r = 1e9;
  while (l <= r) {
    int m = l + r >> 1;
    // cerr << l << " " << m << " " << r << endl;
    if (C(m)) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << r;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}