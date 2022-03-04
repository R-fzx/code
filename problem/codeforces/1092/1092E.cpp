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
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1001;

struct E {
  int d = -1, f;
  bool v;
  vector<int> n;
} e[kN];
struct L {
  int l, x, y;
  bool operator<(const L& o) const { return l > o.l; }
} l[kN];
int n, m, t;
vector<Pii> ans;

void D(int x, int f = 0) {
  e[x].d = e[e[x].f = f].d + 1, e[x].v = 1;
  for (int i : e[x].n) {
    if (i ^ f) {
      D(i, x);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].n.push_back(y), e[y].n.push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    // for (int j = 1; j <= n; ++j) {
    //   cout << e[j].v << " ";
    // }
    // cout << endl;
    if (!e[i].v) {
      // cout << i << endl;
      for (int j = 1; j <= n; ++j) {
        e[j].d = -1;
      }
      D(i);
      int x = max_element(e + 1, e + n + 1, [](const E &a, const E &b) {
        return a.d < b.d;
      }) - e;
      // for (int j = 1; j <= n; ++j) {
      //   cerr << e[j].d << " ";
      // }
      // cerr << endl;
      // cerr << x << endl;
      D(x);
      int y = max_element(e + 1, e + n + 1, [](const E &a, const E &b) {
        return a.d < b.d;
      }) - e, _l = e[y].d;
      // for (int j = 1; j <= n; ++j) {
      //   cerr << e[j].d << " ";
      // }
      // cerr << endl;
      // cerr << x << " " << y << endl;
      for (int i = _l / 2; i--; y = e[y].f) {
      }
      l[++t] = {_l, y, (_l & 1) ? e[y].f : 0};
      // cerr << endl;
    }
  }
    // for (int j = 1; j <= n; ++j) {
    //   cout << e[j].v << " ";
    // }
    // cout << endl;
  sort(l + 1, l + t + 1);
  // for (int i = 1; i <= t; ++i) {
  //   cerr << l[i].x << " " << l[i].y << " " << l[i].l << endl;
  // }
  for (int i = 2; i <= t; ++i) {
    L &x = l[1], y = l[i];
    ans.emplace_back(x.x, y.x);
    if (x.l == y.l) {
      x = {x.l + 1 + !!x.y, x.x, y.x};
    } else if (x.l == y.l + 1) {
      x = {x.l + 1, x.x, (x.y ? 0 : y.x)};
    } else if (x.l == y.l + 2 && x.y) {
      x = {x.l + 1, x.x, 0};
    }
  }
  cout << l[1].l << endl;
  for (Pii &i : ans) {
    cout << i.first << " " << i.second << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}