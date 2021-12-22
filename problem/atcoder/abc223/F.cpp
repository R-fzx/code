// #define TIME
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <numeric>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Tll = tuple<LL, LL, LL>;

const int kN = 2e5 + 1;

int n, q, o, l, r, a[kN];
string s;

struct T {
  struct E {
    int s, t, m;
  } e[kN << 2];

  int L(int x) {
    return x << 1;
  }

  int R(int x) {
    return L(x) | 1;
  }

  void PushUp(int x) {
    e[x].s = e[L(x)].s + e[R(x)].s, e[x].m = min(e[L(x)].m, e[R(x)].m);
  }

  void PushDown(int x, int l, int r) {
    int m = l + r >> 1;
    e[L(x)].s += e[x].t * (m - l + 1), e[L(x)].t += e[x].t, e[L(x)].m += e[x].t;
    e[R(x)].s += e[x].t * (r - m), e[R(x)].t += e[x].t, e[R(x)].m += e[x].t;
    e[x].t = 0;
  }

  void Build(int x, int l, int r) {
    if (l == r) {
      e[x].s = e[x].m = a[l];
      return;
    }
    int m = l + r >> 1;
    Build(L(x), l, m), Build(R(x), m + 1, r);
    PushUp(x);
  }

  void Update(int tl, int tr, int x, int l, int r, int v) {
    if (max(tl, l) > min(tr, r)) {
      return;
    }
    if (tl <= l && r <= tr) {
      e[x].s += v * (r - l + 1), e[x].t += v, e[x].m += v;
      return;
    }
    PushDown(x, l, r);
    int m = l + r >> 1;
    Update(tl, tr, L(x), l, m, v), Update(tl, tr, R(x), m + 1, r, v);
    PushUp(x);
  }

  int Query_min(int tl, int tr, int x, int l, int r) {
    if (max(tl, l) > min(tr, r)) {
      return 1 << 30;
    }
    if (tl <= l && r <= tr) {
      return e[x].m;
    }
    PushDown(x, l, r);
    int m = l + r >> 1;
    return min(Query_min(tl, tr, L(x), l, m), Query_min(tl, tr, R(x), m + 1, r));
  }

  int Query(int tl, int tr, int x, int l, int r) {
    if (max(tl, l) > min(tr, r)) {
      return 0;
    }
    if (tl <= l && r <= tr) {
      return e[x].s;
    }
    PushDown(x, l, r);
    int m = l + r >> 1;
    return Query(tl, tr, L(x), l, m) + Query(tl, tr, R(x), m + 1, r);
  }
} t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> q >> s;
  s = "#" + s;
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
  }
  t.Build(1, 1, n);
  while (q--) {
    cin >> o >> l >> r;
    if (o == 1) {
      if (s[l] != s[r]) {
        t.Update(l, r - 1, 1, 1, n, s[l] == ')' ? 2 : -2);
        swap(s[l], s[r]);
      }
    } else {
      int x = t.Query(l - 1, l - 1, 1, 1, n);
      cout << (t.Query_min(l, r, 1, 1, n) - x >= 0 && t.Query(r, r, 1, 1, n) - x == 0 ? "Yes" : "No") << endl;
    }
  }
#ifdef TIME
  double t = clock() * 1.0 / CLOCKS_PER_SEC;
  cerr << "\n\nTIME: " << t << "s\n";
#endif
  return 0;
}