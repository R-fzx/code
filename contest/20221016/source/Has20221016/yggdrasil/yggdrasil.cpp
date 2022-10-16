#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int N = 7e5 + 1;

struct E {
  int x, d;
  ll ans;
  vector<pii> e;
} v[N];

int n, ansi, x, y, z;
ll ans_min = 1e18;

void Dfs(int x, int f, ll s) {
  v[1].ans += s;
  v[x].d = 1;
  for (pii i : v[x].e) {
    if (i.first != f) {
      Dfs(i.first, x, s + i.second - v[x].x);
      v[x].d += v[i.first].d;
    }
  }
}

void Hg(int x, int f, int e) {
  if (x != 1) {
    v[x].ans = v[f].ans - v[x].d * (e - v[f].x) + (n - v[x].d) * (e - v[x].x);
    if (v[x].ans < ans_min) {
      ans_min = v[x].ans, ansi = x;
    } else if (v[x].ans == ans_min && x < ansi) {
      ansi = x;
    }
  }
  for (pii i : v[x].e) {
    if (i.first != f) {
      Hg(i.first, x, i.second);
    }
  }
}

int main() {
  freopen("yggdrasil.in", "r", stdin);
  freopen("yggdrasil.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i].x;
  }
  for (int i = 1; i < n; ++i) {
    cin >> x >> y >> z;
    v[x].e.push_back({y, z});
    v[y].e.push_back({x, z});
  }
  Dfs(1, 0, 0);
  ansi = 1, ans_min = v[1].ans;
  Hg(1, 0, 0);
  cout << ansi << '\n' << ans_min;
  return 0;
}