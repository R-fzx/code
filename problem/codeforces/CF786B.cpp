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
#include <set>
#include <string>
#include <vector>
// #define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1, kV = kN << 2;

int n, q, s;
vector<Pll> e[kN * 9];
LL d[kN * 9];
priority_queue<Pll, vector<Pll>, greater<Pll>> l;

/*
o=0: 点到区间
o=1: 区间到点
*/
void Build(int o, int x, int l, int r, int _ = 0) {
  debug("% *sBuild(%d, %d, %d, %d) Start.\n", _ * 2, "", o, x, l, r);
  if (l == r) {
    if (o) {
      e[l + kV * 2].push_back({x + kV, 0});
    } else {
      e[x].push_back({l + kV * 2, 0});
    }
    debug("% *sBuild(%d, %d, %d, %d) Stop.\n", _ * 2, "", o, x, l, r);
    return;
  }
  int m = l + r >> 1;
  if (o) {
    e[x * 2 + kV].push_back({x + kV, 0}), e[x * 2 + 1 + kV].push_back({x + kV, 0});
  } else {
    e[x].push_back({x * 2, 0}), e[x].push_back({x * 2 + 1, 0});
  }
  Build(o, x * 2, l, m, _ + 1), Build(o, x * 2 + 1, m + 1, r, _ + 1);
  debug("% *sBuild(%d, %d, %d, %d) End.\n", _ * 2, "", o, x, l, r);
}
void Connect(int o, int x, int l, int r, int tl, int tr, int y, int w, int _ = 0) {
  debug("% *sConnect(%d, %d, %d, %d, %d, %d, %d, %d) Start.\n", _ * 2, "", o, x, l, r, tl, tr, y, w);
  if (l == tl && r == tr) {
    if (o) {
      e[x + kV].push_back({y + kV * 2, w});
    } else {
      e[y + kV * 2].push_back({x, w});
    }
    debug("% *sConnect(%d, %d, %d, %d, %d, %d, %d, %d) Stop.\n", _ * 2, "", o, x, l, r, tl, tr, y, w);
    return;
  }
  int m = l + r >> 1;
  if (tl <= m) {
    Connect(o, x * 2, l, m, tl, min(tr, m), y, w, _ + 1);
  }
  if (m < tr) {
    Connect(o, x * 2 + 1, m + 1, r, max(tl, m + 1), tr, y, w, _ + 1);
  }
  debug("% *sConnect(%d, %d, %d, %d, %d, %d, %d, %d) End.\n", _ * 2, "", o, x, l, r, tl, tr, y, w);
}
void R(int x, LL _d) {
  if (d[x] > _d) {
    d[x] = _d, l.push({_d, x});
  }
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q >> s;
  Build(0, 1, 1, n), Build(1, 1, 1, n);
  for (int i = 1, o, x, l, r, w; i <= q; ++i) {
    cin >> o >> x >> l;
    if (o ^ 1) {
      cin >> r;
    }
    cin >> w;
    if (o == 1) {
      e[x + kV * 2].push_back({l + kV * 2, w});
    } else {
      Connect(o - 2, 1, 1, n, l, r, x, w);
    }
  }
  fill(d + 1, d + kN * 9, 1e18);
  for (R(s + kV * 2, 0); !l.empty();) {
    int x = l.top().second;
    l.pop();
    // cerr << x << " " << d[x] << endl;
    for (Pll &y : e[x]) {
      // cerr << "  " << y.first << " " << y.second << endl;
      R(y.first, d[x] + y.second);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << (d[i + kV * 2] == 1e18 ? -1 : d[i + kV * 2]) << " ";
  }
  return 0;
}