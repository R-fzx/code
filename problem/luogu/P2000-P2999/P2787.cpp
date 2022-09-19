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

const int kN = 5e4 + 1, kC = 26;
using A = array<int, kC>;

const A operator+(const A &x, const A &y) {
  A s;
  for (int i = 0; i < kC; ++i) {
    s[i] = x[i] + y[i];
  }
  return s;
}
struct E {
  A s;
  int t = -1;
} e[kN << 2];
int n, q;

void Pa(int x, int l, int r, int v) { e[x].s.fill(0), e[x].s[v] = r - l + 1, e[x].t = v; }
void Pu(int x) { e[x].s = e[x * 2].s + e[x * 2 + 1].s; }
int G() {
  char v;
  cin >> v;
  return tolower(v) - 'a';
}
void B(int x, int l, int r) {
  if (l == r) {
    e[x].s[G()] = 1;
    return;
  }
  int m = l + r >> 1;
  B(x * 2, l, m), B(x * 2 + 1, m + 1, r);
  Pu(x);
}
void Assign(int x, int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) {
    Pa(x, l, r, v);
    return;
  }
  int m = l + r >> 1;
  ~e[x].t && (Pa(x * 2, l, m, e[x].t), Pa(x * 2 + 1, m + 1, r, e[x].t), e[x].t = -1);
  if (tl <= m) {
    Assign(x * 2, l, m, tl, min(m, tr), v);
  }
  if (m < tr) {
    Assign(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, v);
  }
  Pu(x);
}
A Query(int x, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    return e[x].s;
  }
  int m = l + r >> 1;
  A s;
  s.fill(0), ~e[x].t && (Pa(x * 2, l, m, e[x].t), Pa(x * 2 + 1, m + 1, r, e[x].t), e[x].t = -1);
  if (tl <= m) {
    s = s + Query(x * 2, l, m, tl, min(m, tr));
  }
  if (m < tr) {
    s = s + Query(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
  }
  Pu(x);
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  B(1, 1, n);
  for (int o, l, r; q--;) {
    cin >> o >> l >> r;
    if (o == 1) {
      cout << Query(1, 1, n, l, r)[G()] << '\n';
    } else if (o == 2) {
      Assign(1, 1, n, l, r, G());
    } else {
      A x = Query(1, 1, n, l, r);
      for (int i = 0; i < kC; ++i) {
        if (x[i]) {
          Assign(1, 1, n, l, l + x[i] - 1, i), l += x[i];
        }
      }
    }
  }
  return 0;
}