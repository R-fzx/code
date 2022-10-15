#include <algorithm>
#include <iostream>
#include <vector>
#define LL unsigned long long

using namespace std;

const LL kInf = 1e18;
struct E {
  LL x, y, a, b;
} e[50001];
struct V {
  LL d, p, v, f;
  vector<pair<LL, LL>> e;
} v[201];
LL n, m, p, q, c = 1, mx, ans = kInf;

LL Read() {
  LL x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

LL GetRoot(LL x) {
  return v[x].f == x ? x : v[x].f = GetRoot(v[x].f);
}

LL MST() {
  LL i = 1, mx = 0;
  for (; i <= m && c < n; i++) {
    if (GetRoot(e[i].x) != GetRoot(e[i].y)) {
      c++, mx = max(mx, e[i].b);
      v[GetRoot(e[i].x)].f = GetRoot(e[i].y);
      v[e[i].x].e.push_back({e[i].y, e[i].b}), v[e[i].y].e.push_back({e[i].x, e[i].b});
    }
  }
  if (c == n) {
    ans = min(ans, e[i - 1].a * p + mx * q);
  }
  return i;
}

void T(LL f, LL x) {
  for (auto i : v[x].e) {
    if (i.first != f) {
      v[i.first].d = v[x].d + 1;
      v[i.first].p = x;
      mx = max(mx, v[i.first].v = i.second);
      T(x, i.first);
    }
  }
}

void Delete(LL x, LL y) {
  for (LL i = 0; i < v[x].e.size(); i++) {
    if (v[x].e[i].first == y) {
      for (LL j = i + 1; j < v[x].e.size(); j++) {
        v[x].e[j - 1] = v[x].e[j];
      }
      v[x].e.pop_back();
      break;
    }
  }
}

void Update(LL x, LL y, LL b) {
  LL mx = 0, _x, _y;
  if (v[x].d < v[y].d) {
    swap(x, y);
  }
  _x = x, _y = y;
  for (; v[_x].d > v[_y].d; _x = v[_x].p) {
    mx = max(mx, v[_x].v);
  }
  for (; _x != _y; _x = v[_x].p, _y = v[_y].p) {
    mx = max(mx, max(v[_x].v, v[_y].v));
  }
  if (mx <= b) {
    return;
  }
  _x = x, _y = y;
  for (; v[_x].d > v[_y].d; _x = v[_x].p) {
    if (mx == v[_x].v) {
      Delete(_x, v[_x].p), Delete(v[_x].p, _x);
      v[x].e.push_back({y, b}), v[y].e.push_back({x, b});
      return;
    }
  }
  for (; _x != _y; _x = v[_x].p, _y = v[_y].p) {
    if (mx == v[_x].v) {
      Delete(_x, v[_x].p), Delete(v[_x].p, _x);
      v[x].e.push_back({y, b}), v[y].e.push_back({x, b});
      return;
    } else if (mx == v[_y].v) {
      Delete(_y, v[_y].p), Delete(v[_y].p, _y);
      v[x].e.push_back({y, b}), v[y].e.push_back({x, b});
      return;
    }
  }
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  n = Read(), m = Read(), p = Read(), q = Read();
  for (LL i = 1; i <= m; i++) {
    e[i].x = Read(), e[i].y = Read(), e[i].a = Read(), e[i].b = Read();
  }
  sort(e + 1, e + m + 1, [](E i, E j) { return i.a < j.a || i.a == j.a && i.b < j.b; });
  for (LL i = 1; i <= n; i++) {
    v[i].f = i;
  }
  for (LL i = MST(); i <= m; i++) {
    mx = 0, T(0, 1), ans = min(ans, e[i - 1].a * p + mx * q);
    Update(e[i].x, e[i].y, e[i].b);
  }
  if (c == n) {
    mx = 0, T(0, 1), ans = min(ans, e[m].a * p + mx * q);
  }
  cout << (ans == kInf ? -1 : ans);
  return 0;
}
