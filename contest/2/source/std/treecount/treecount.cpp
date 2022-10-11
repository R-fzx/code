#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
const int kN = 1e3 + 5, kE = 1e6 + 5;  // 开大点就不会越界（）
const ll kM = 2147483647;              // 记得取模

struct Edge {
  int v, nxt, w;
} ed[kE];  // 链式前向星
bool t[kN];
queue<int> q;
ll s[kN], ans = 1ll;
int n, m, d[kE], h[kE], tot;

void A(int u, int v, int w) {  // 加边
  ed[++tot] = {v, h[u], w}, h[u] = tot;
  ed[++tot] = {u, h[v], w}, h[v] = tot;
}
void S() {  // 某已死算法（）我不管这是信仰
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
        s[v] = 1;  // 找到更优解，方案数归 1
        if (!t[v]) {
          q.push(v);
          t[v] = true;
        }
      } else if (d[x] + w == d[v]) {  // 和当前最短路相等，则++。
        s[v]++;
      }
    }
    t[x] = false;
  }
}
int main() {
  freopen("treecount.in", "r", stdin);
  freopen("treecount.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; i++) {  // 读边
    cin >> u >> v >> w, A(u, v, w);
  }
  S();  // 跑最短路
  for (int i = 1; i <= n; i++) {
    ans = (ans * s[i]) % kM;  // 方案数之积
  }
  cout << ans << '\n';
  return 0;
}

/**
 * author :  Lightwhite
 * time :  2022/10/10 20:30
 */