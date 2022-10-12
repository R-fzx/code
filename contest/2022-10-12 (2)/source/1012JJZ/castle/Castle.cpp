/**
 * @file Castle.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief Castle
 * @version 0.1
 * @date 2022-10-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
const int kN = 1e3 + 5, kE = 1e6 + 5;
const ll kM = 2147483647;

struct Edge {
  int v, nxt, w;
} ed[kE]; 
bool t[kN];
queue<int> q;
ll s[kN], ans = 1ll;
int n, m, d[kE], h[kE], tot;
void A(int u, int v, int w) {
  ed[++tot] = {v, h[u], w}, h[u] = tot;
  ed[++tot] = {u, h[v], w}, h[v] = tot;
}
void S() {
  memset(d, 0x7f, sizeof(d));
  memset(t, false, sizeof(t));
  fill(s + 1, s + n + 1, 1);
  q.push(1);
  d[1] = 0;
  t[1] = true;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = h[x], v, w; i; i = ed[i].nxt) {
      v = ed[i].v, w = ed[i].w;
      if (d[x] + w < d[v]) {
        d[v] = d[x] + w;
        s[v] = 1;
        if (!t[v]) {
          q.push(v);
          t[v] = true;
        }
      } else if (d[x] + w == d[v]) {
        s[v]++;
      }
    }
    t[x] = false;
  }
}
int main() {
  freopen("Castle.in", "r", stdin);
  freopen("Castle.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w, A(u, v, w);
  }
  S();
  for (int i = 1; i <= n; i++) {
    ans = (ans * s[i]) % kM;
  }
  cout << ans << '\n';
  return 0;
}