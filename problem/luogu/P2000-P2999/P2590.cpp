#include <functional>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;

const int kN = 30001;
function<LL(LL, LL)> kO[2] = {[](LL a, LL b) { return max(a, b); }, [](LL a, LL b) { return a + b; }};

struct E {
  int f, t, d, s, h, p;
  vector<int> e;
} a[kN];
Pll e[kN << 2];
int n, q, c, x, y;
string o;

void D(int x, int f) {
  a[x].f = f, a[x].s = 1;
  for (int i : a[x].e) {
    if (i != f) {
      D(i, x), a[x].s += a[i].s, a[i].s > a[a[x].h].s && (a[x].h = i);
    }
  }
}
void H(int x, int t) {
  if (x) {
    a[x].t = t, a[x].p = ++c, a[x].d = a[a[x].f].d + 1, H(a[x].h, t);
    for (int i : a[x].e) {
      if (i != a[x].f && i != a[x].h) {
        H(i, i);
      }
    }
  }
}
LL Do(int ty, int x, int l, int r, int tl, int tr, LL v) {
  if (l == tl && r == tr) {
    if (!ty) {
      e[x].first = e[x].second = v;
    }
    return ty == 1 ? e[x].first : e[x].second;
  }
  int m = l + r >> 1;
  LL s = (ty == 1 ? INT32_MIN : 0);
  if (tl <= m) {
    s = kO[max(0, ty - 1)](s, Do(ty, x * 2, l, m, tl, min(tr, m), v));
  }
  if (m < tr) {
    s = kO[max(0, ty - 1)](s, Do(ty, x * 2 + 1, m + 1, r, max(tl, m + 1), tr, v));
  }
  e[x].first = max(e[x * 2].first, e[x * 2 + 1].first), e[x].second = e[x * 2].second + e[x * 2 + 1].second;
  return s;
}
LL S(int x, int y, int f) {
  LL s = (f ? 0 : INT32_MIN);
  for (; a[x].t != a[y].t; x = a[a[x].t].f) {
    if (a[a[x].t].d < a[a[y].t].d) {
      swap(x, y);
    }
    s = kO[f](s, Do(f + 1, 1, 1, n, a[a[x].t].p, a[x].p, 0));
  }
  if (a[x].d > a[y].d) {
    swap(x, y);
  }
  return kO[f](s, Do(f + 1, 1, 1, n, a[x].p, a[y].p, 0));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    a[x].e.push_back(y), a[y].e.push_back(x);
  }
  D(1, 0), H(1, 1);
  for (int i = 1, v; i <= n; ++i) {
    cin >> v;
    Do(0, 1, 1, n, a[i].p, a[i].p, v);
  }
  cin >> q;
  while (q--) {
    cin >> o >> x >> y;
    if (o.back() == 'E') {
      Do(0, 1, 1, n, a[x].p, a[x].p, y);
    } else {
      cout << S(x, y, o.back() == 'M') << '\n';
    }
  }
  return 0;
}