#include <algorithm>
#include <iostream>

using namespace std;

const int kN = 1e5 + 1, kK = 2e5 + 1;

struct E {
  int a, b, c, _c = 1, f;
  bool operator<(const E &o) const {
    return a < o.a || a == o.a && (b < o.b || b == o.b && c < o.c);
  }
} e[kN], _e[kN];
int n, k, m, c[kN], s[kK];

void A(int x, int v) {
  for (; x <= k; s[x] += v, x += x & -x) {
  }
}
int Q(int x) {
  int _s = 0;
  for (; x; _s += s[x], x -= x & -x) {
  }
  return _s;
}
void S(int l, int r) {
  if (l == r) {
    return;
  }
  int m = l + r >> 1;
  S(l, m), S(m + 1, r);
  for (int i = l, j = m + 1, k = l; k <= r; ) {
    if (j > r || (i <= m && e[i].b <= e[j].b)) {
      A(e[i].c, e[i]._c), _e[k++] = e[i++];
    } else {
      e[j].f += Q(e[j].c), _e[k++] = e[j++];
    }
  }
  for (int i = l; i <= m; ++i) {
    A(e[i].c, -e[i]._c);
  }
  copy(_e + l, _e + r + 1, e + l);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i].a >> e[i].b >> e[i].c;
  }
  sort(e + 1, e + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (e[i].a == e[m].a && e[i].b == e[m].b && e[i].c == e[m].c) {
      ++e[m]._c;
    } else {  
      e[++m] = e[i];
    }
  }
  S(1, m);
  for (int i = 1; i <= m; ++i) {
    c[e[i].f + e[i]._c - 1] += e[i]._c;
  }
  for (int i = 0; i < n; ++i) {
    cout << c[i] << '\n';
  }
  return 0;
}