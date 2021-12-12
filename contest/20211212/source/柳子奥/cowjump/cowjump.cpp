#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using ldb = long double;
using pdd = pair <ldb, ldb>;

const int N = 1e5 + 5;

struct line {
  ldb k, b;
  ll fx, fy, tx, ty;

  line () {}
  line (ll _x1, ll _y1, ll _x2, ll _y2) {
    fx = _x1, tx = _x2;
    fy = _y1, ty = _y2;
    k = 1.0 * (_y2 - _y1) / (_x2 - _x1), b = 1.0 * (1ll * _y2 * _x1 - 1ll * _y1 * _x2) / (_x2 - _x1);
  }
} jlq[N] ;

int n;
int a, b, c, d;
int f[N], cnt;

pdd JLQ (line a, line b) {
  if (a.k == b.k) return make_pair(-1, -1);
  ldb x = (a.b - b.b) / (a.k - b.k), y = (ldb)(a.k * x + a.b);
  return make_pair(x, y);
}

int main() {
  freopen("cowjump.in", "r", stdin);
  freopen("cowjump.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a > c) swap(a, c), swap(b, d);
    jlq[i] = line(a, b, c, d);
  }
  // cerr << "fuck" << endl;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      pdd pt = JLQ(jlq[i], jlq[j]);
      if (pt.first >= jlq[i].fx && pt.first <= jlq[i].tx && pt.first >= jlq[j].fx && pt.first <= jlq[j].tx)
        ++f[i], ++f[j], ++cnt;
    }
  for (int i = 1; i <= n; ++i)
    if (f[i] == cnt) {
      printf("%d\n", i);
      break ;
    }
  // else {
  //   srand(time(NULL));
  //   int maxn = 0, idx = 0, x, y;
  //   int cntx = 0, cnty = 0;
  //   // pdd pt = JLQ(jlq[1], jlq[2]);
  //   // cerr << (ldb)pt.first << " " << (ldb)pt.second << endl;
  //   do {
  //     x = rand() % n + 1, y = rand() % (x - 1) + 1;
  //     // cerr << x << " " << y << " " << clock() << endl;
  //     pdd pt = JLQ(jlq[x], jlq[y]);
  //     if (!(pt.first >= jlq[x].fx && pt.first <= jlq[x].tx && pt.first >= jlq[y].fx && pt.first <= jlq[y].tx))
  //       continue ;
  //     // cerr << "shit" << endl;
  //     break ;
  //   } while (clock() <= 900) ;
  //   for (int i = 1; i <= n; ++i) {
  //     if (i == x) continue ;
  //     pdd pt = JLQ(jlq[i], jlq[x]);
  //     if (pt.first >= jlq[x].fx && pt.first <= jlq[x].tx && pt.first >= jlq[i].fx && pt.first <= jlq[i].tx)
  //       ++cntx;
  //   }
  //   for (int i = 1; i <= n; ++i) {
  //     if (i == y) continue ;
  //     pdd pt = JLQ(jlq[i], jlq[y]);
  //     if (pt.first >= jlq[i].fx && pt.first <= jlq[i].tx && pt.first >= jlq[y].fx && pt.first <= jlq[y].tx)
  //       ++cnty;
  //   }
  //   if (cntx > cnty) printf("%d\n", x);
  //   else printf("%d\n", y);
  // }
  // cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}