#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1001;

struct E {
  int x, d;
  bool f;
  vector<int> e;
} v[N];

int n, ans;

void Prim() {
  for (int i = 1; i <= n; ++i) {
    int p = 0;
    for (int j = 1; j <= n; ++j) {
      if (!v[j].f && (!p || v[j].d > v[p].d || v[j].d == v[p].d && v[j].x > v[p].x)) {
        p = j;
      }
    }
    v[p].f = 1;
    ans += v[p].d;
    for (int j : v[p].e) {
      v[j].d = max(v[j].d, v[p].x);
    }
  }
}

int main() {
  freopen("graph.in", "r", stdin);
  freopen("graph.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i].x;
    for (int j = 1; j < i; ++j) {
      if (!(v[i].x & v[j].x)) {
        v[i].e.push_back(j);
        v[j].e.push_back(i);
      }
    }
  }
  Prim();
  cout << ans;
  return 0;
}