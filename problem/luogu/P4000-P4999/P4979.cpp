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
using A = array<int, 3>;

const int kN = 5e5 + 1;

struct E {
  A s;
  int t = -1;
} e[kN << 2];
int n, q;

const A operator+(const A &x, const A &y) {
  A s;
  for (int i = 0; i < 3; ++i) {
    s[i] = x[i] + y[i];
  }
  return s;
}
int G() {
  char c;
  cin >> c;
  return c - 'A';
}
void Pa(int x, int l, int r, int v) { e[x].s.fill(0), e[x].s[v] = r - l + 1, e[x].t = v; }
void Pu(int x) { e[x].s = e[x * 2].s + e[x * 2 + 1].s; }
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
A Sum(int x, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    return e[x].s;
  }
  int m = l + r >> 1;
  A s;
  s.fill(0), ~e[x].t && (Pa(x * 2, l, m, e[x].t), Pa(x * 2 + 1, m + 1, r, e[x].t), e[x].t = -1);
  if (tl <= m) {
    s = s + Sum(x * 2, l, m, tl, min(m, tr));
  }
  if (m < tr) {
    s = s + Sum(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
  }
  Pu(x);
  return s;
}
bool C(int l, int r) {
  A x = Sum(1, 1, n, l, r);
  for (int i = 0; i < 3; ++i) {
    if (x[i] == r - l + 1 && (l == 1 || r == n || Sum(1, 1, n, l - 1, l - 1) != Sum(1, 1, n, r + 1, r + 1))) {
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  B(1, 1, n);
  cin >> q;
  for (int l, r; q--;) {
    char o;
    cin >> o >> l >> r;
    if (o == 'A') {
      Assign(1, 1, n, l, r, G());
    } else {
      cout << (C(l, r) ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}