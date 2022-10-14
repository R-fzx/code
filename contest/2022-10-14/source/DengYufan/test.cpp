#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
#define PLL pair<LL, LL>

using namespace std;

struct E {
  LL x, y, z;
} e[300001];
struct V {
  LL d, f[17];
  PLL v[17];
  vector<PLL> e;
} v[100001];
LL n, m, s, ans = 1e18, f[100001];

LL GetRoot(LL x) {
  return f[x] == x ? x : f[x] = GetRoot(f[x]);
}

void T(LL f, LL x) {
  for (auto i : v[x].e) {
    if (i.first != f) {
      v[i.first].d = v[x].d + 1, v[i.first].f[0] = x, v[i.first].v[0].first = i.second;
      T(x, i.first);
    }
  }
}

PLL Update(PLL x, LL y) {
  if (x.first < y) {
    x.second = x.first, x.first = y;
  } else if (x.first > y) {
    x.second = max(x.second, y);
  }
  return x;
}

PLL Lca(LL x, LL y) {
  PLL t = {0, 0};
  if (v[x].d < v[y].d) {
    swap(x, y);
  }
  for (LL i = 16; i >= 0; i--) {
    if (v[x].d - (1 << i) >= v[y].d) {
      t = Update(Update(v[x].v[i], t.first), t.second);
      x = v[x].f[i];
    }
  }
  for (LL i = 16; i >= 0; i--) {
    if (v[x].f[i] != v[y].f[i]) {
      t = Update(Update(v[x].v[i], t.first), t.second);
      t = Update(Update(v[y].v[i], t.first), t.second);
      x = v[x].f[i], y = v[y].f[i];
    }
  }
  if (x != y) {
    t = Update(Update(v[x].v[0], t.first), t.second);
    t = Update(Update(v[y].v[0], t.first), t.second);
  }
  return t;
}

int main() {
  cin >> n >> m;
  for (LL i = 1; i <= m; i++) {
    cin >> e[i].x >> e[i].y >> e[i].z;
  }
  sort(e + 1, e + m + 1, [](E i, E j) { return i.z < j.z; });
  for (LL i = 1; i <= n; i++) {
    f[i] = i;
  }
  for (LL i = 1; i <= m; i++) {
    if (GetRoot(e[i].x) != GetRoot(e[i].y)) {
      s += e[i].z;
      v[e[i].x].e.push_back({e[i].y, e[i].z}), v[e[i].y].e.push_back({e[i].x, e[i].z});
      f[GetRoot(e[i].x)] = GetRoot(e[i].y);
    }
  }
  T(0, 1);
  for (LL i = 1; i <= 16; i++) {
    for (LL j = 1; j <= n; j++) {
      v[j].f[i] = v[v[j].f[i - 1]].f[i - 1];
      v[j].v[i] = Update(Update(v[v[j].f[i - 1]].v[i - 1], v[j].v[i - 1].first), v[j].v[i - 1].second);
    }
  }
  for (LL i = 1; i <= m; i++) {
    PLL x = Lca(e[i].x, e[i].y);
    if (e[i].z > x.first) {
      ans = min(ans, e[i].z - x.first);
    } else if (e[i].z > x.second) {
      ans = min(ans, e[i].z - x.second);
    }
  }
  cout << s + ans;
  return 0;
}
