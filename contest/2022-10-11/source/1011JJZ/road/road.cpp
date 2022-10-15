#include <iostream>
#include <algorithm>
#include <cstring>

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define put(x) (cout << (x) << '\n')
#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)

using namespace std;
using ll = long long;
const int kN = 5e5 + 5;

int P, R, tot, cnt;
ll Ca, Cb, ans, inf;
struct Edge {
  int x, y;
  ll wx, wy;
  bool operator < (const Edge &k) const {
    return wx < k.wx || wx == k.wx && wy < k.wy;
  }
} ed[kN];
struct Lis {
  ll w;
  int k;
  Lis *nxt, *pre, *ano;
} list[kN << 1], p[205];
void L (int x, int y, ll w) {
  Lis *l1 = &list[tot++], *l2 = &list[tot++];
  l1 -> k = y, l2 -> k = x, l1 -> w = l2 -> w = w, l1 -> ano = l2, l2 -> ano = l1;
  l1 -> nxt = p[x].nxt, p[x].nxt = l1, l2 -> nxt = p[y].nxt, p[y].nxt = l2;
  l1 -> pre = l1 -> nxt -> pre, l1 -> nxt -> pre = l1, l2 -> pre = l2 -> nxt -> pre, l2 -> nxt -> pre = l2;
}
void D (Lis *l) {
  l -> pre -> nxt = l -> nxt, l -> nxt -> pre = l -> pre;
  l = l -> ano;
  l -> pre -> nxt = l -> nxt, l -> nxt -> pre = l -> pre;
}
ll U (ll w) {
  ll r = 0;
  for (int i = 1; i <= P; i++) {
    for (Lis *l = p[i].nxt; l != &p[i]; l = l -> nxt) {
      r = max (r, l -> w);
    }
  }
  return w * Ca + r * Cb;
}
bool J (int x, int y, int f, Lis *&lis) {
  if (x == y) {
    return true;
  }
  for (Lis *l = p[x].nxt; l != &p[x]; l = l -> nxt) {
    if (l -> k != f && J (l -> k, y, x, lis)) {
      (!lis || l -> w > lis -> w) && (lis = l);
      return true;
    }
  }
  return false;
}
void A (Edge e) {
  Lis *k = {0};
  if (e.x == e.y) {
    return ;
  }
  if (!J (e.x, e.y, 0, k)) {
    cnt++, L (e.x, e.y, e.wy);
  } else if (e.wy < k -> w) {
    D (k), L (e.x, e.y, e.wy);
  }
  if (cnt == P - 1) {
    ans = min (ans, U (e.wx));
  }
}
int main () {
  file ("road");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> P >> R >> Ca >> Cb;
  for (int i = 1; i <= R; i++) {
    cin >> ed[i].x >> ed[i].y >> ed[i].wx >> ed[i].wy;
  }
  sort (ed + 1, ed + R + 1), inf = ans = 1ll * 1e9 * (Ca + Cb);
  for (int i = 1; i <= P; i++) {
    p[i].nxt = p[i].pre = &p[i];
  }
  for_each (ed + 1, ed + R + 1, [&] (Edge &e) { A (e); });
  put (ans == inf ? -1 : ans);
  return 0;
}