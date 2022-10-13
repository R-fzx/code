#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int M = 3001, N = 1001;

struct E {
  int x, y, l, r;
} v[M];

int n, m, f[N], ansl, ansr;

int Find(int x) {
  return f[x] == x ? x : f[x] = Find(f[x]);
}

int S(int l) {
  for (int i = 1; i <= n; ++i) {
    f[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    if (v[i].l > l) {
      continue;
    }
    int x = Find(v[i].x), y = Find(v[i].y);
    f[x] = y;
    if (Find(1) == Find(n)) {
      return v[i].r;
    }
  }
  return -1e9;
}

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> v[i].x >> v[i].y >> v[i].l >> v[i].r;
  }
  sort(v + 1, v + m + 1, [](E a, E b) { return a.r > b.r; });
  for (int i = 1; i <= m; ++i) {
    int l = v[i].l, r = S(l);
    if (r - l + 1 > ansr - ansl + 1) {
      ansl = l, ansr = r;
    } else if (r - l + 1 == ansr - ansl + 1 && l < ansl) {
      ansl = l, ansr = r;
    }
  }
  cout << ansr - ansl + 1 << '\n';
  for (int i = ansl; i <= ansr; ++i) {
    cout << i << ' ';
  }
  return 0;
}