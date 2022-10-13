/**
 * @file travel.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief travel (problem of 1class contest)
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
const int kN = 3e3 + 5;

struct Edge {
  int u, v, l, r;
} ed[kN];
int n, m, r[kN], fa[kN], s, k;
int R(int x) {
  return fa[x] == x ? x : fa[x] = R(fa[x]);
}
int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> ed[i].u >> ed[i].v >> ed[i].l >> ed[i].r;
    r[i] = ed[i].r;
  }
  sort(r + 1, r + m + 1);
  sort(ed + 1, ed + m + 1, [&](Edge &e1, Edge &e2) { 
    return e1.l < e2.l;
  });
  for (int i = 1; i <= m; i++) {
    iota(fa + 1, fa + n + 1, 1);
    for (int j = 1; j <= m; j++) {
      if (ed[j].r >= r[i]) {
        int ru = R(ed[j].u), rv = R(ed[j].v);
        if (ru != rv) {
          fa[ru] = rv;
        }
        if (R(1) == R(n) && r[i] - ed[j].l + 1 > s) {
          s = r[i] - ed[j].l + 1;
          k = ed[j].l;
        }
      }
    }
  }
  cout << s << '\n';
  for (int i = k; i <= s + k - 1; i++) {
    cout << i << ' ';
  }
  return 0;
}