#include <iostream>
#include <vector>

using namespace std;

struct MCMF {
  static const int kN = 10003, kM = 18001;
  struct V {
    int h, _h, d;
    bool v;
  } a[kN];
  struct E {
    int y, n, w, c;
  } e[kM << 1];
  int n, s, t, _c = 1, q[kN], _h, _t;
  int mf, mc;
  void _A(int x, int y, int w, int c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, int w, int c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, int d) {
    if (a[x].d > d) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = 1e9;
    }
    for (R(s, 0); _h != _t;) {
      int x = q[_h = (_h + 1) % kN];
      a[x].v = 0;
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w) {
          R(e[i].y, a[x].d + e[i].c);
        }
      }
    }
    return a[t].d < 1e9;
  }
  int D(int x, int f) {
    if (x == t) {
      return f;
    }
    if (a[x].v) {
      return 0;
    }
    a[x].v = 1;
    int s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, 1e9)) {
    }
  }
} sl;
int n, m;

void A(int x, int y, int w, int c, int t) { sl.A(t ? y : x, t ? x : y, w, c); }
int E(int x, int y, int d) { return (x - 1) * m + y + d * n * m; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  sl.n = sl.t = (sl.s = 5 * n * m + 1) + 1;
  int smf = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j <= m; ++j) {
      int t = i + j & 1;
      for (int k = 1; k < 3; ++k) {
        int ni = i + (k == 2), nj = j + (k == 1);
        if (ni <= n && nj <= m) {
          A(E(i, j, k), E(ni, nj, k ^ 2), 1, 0, t);
        }
      }
      A(t ? sl.t : sl.s, E(i, j, 4), 4, 0, t);
      cin >> x;
      vector<int> l;
      for (int k = 0; k < 4; ++k) {
        if (x >> k & 1) {
          l.push_back(k);
          A(E(i, j, 4), E(i, j, k), 1, 0, t);
        }
      }
      smf += l.size();
      if (l.size() == 1) {
        A(E(i, j, l[0]), E(i, j, (l[0] + 1) % 4), 1, 1, t), A(E(i, j, l[0]), E(i, j, (l[0] + 3) % 4), 1, 1, t);
        A(E(i, j, l[0]), E(i, j, l[0] ^ 2), 1, 2, t);
      } else if (l.size() == 2 && (l[0] ^ l[1] ^ 2)) {
        A(E(i, j, l[0]), E(i, j, l[0] ^ 2), 1, 1, t), A(E(i, j, l[1]), E(i, j, l[1] ^ 2), 1, 1, t);
      } else if (l.size() == 3) {
        int v = l[0] ^ l[1] ^ l[2];
        for (int k : l) {
          A(E(i, j, k), E(i, j, v), 1, 1 + !(k ^ v ^ 2), t);
        }
      }
    }
  }
  sl.S();
  cout << (sl.mf * 2 == smf ? sl.mc : -1);
  return 0;
}