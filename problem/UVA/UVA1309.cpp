#include <iostream>
#define debug cerr << "QwQ" << endl

using namespace std;

const int kR = 16 * 16 * 16, kC = 16 * 16 * 4, kN = kR * 4;

struct S {
  struct E {
    int u, d, l, r, i, j;
  } e[kN + kR + kC + 1];
  int _c, f[kR + 1], s[kC + 1], st[kR + 1], t;

  void Build(int r, int c) {
    for (int i = 0; i <= c; ++i) e[i] = {i, i, i - 1, i + 1, 0, 0};
    e[0].l = c, e[c].r = 0, _c = c, fill(f + 1, f + r + 1, 0), fill(s + 1, s + c + 1, 0), t = 0;
  }
  void Insert(int r, int c) {
    if (++_c, !f[r]) f[r] = e[_c].r = _c;
    e[_c] = {c, e[c].d, f[r], e[f[r]].r, r, c}, e[c].d = e[e[c].d].u = e[f[r]].r = e[e[f[r]].r].l = _c, ++s[c];
  }
  void Delete(int x) {
    e[e[x].l].r = e[x].r, e[e[x].r].l = e[x].l;
    for (int i = e[x].d; i != x; i = e[i].d)
      for (int j = e[i].r; j != i; j = e[j].r) e[e[j].u].d = e[j].d, e[e[j].d].u = e[j].u, --s[e[j].j];
  }
  void Recover(int x) {
    for (int i = e[x].u; i != x; i = e[i].u)
      for (int j = e[i].l; j != i; j = e[j].l) e[e[j].u].d = e[e[j].d].u = j, ++s[e[j].j];
    e[e[x].l].r = e[e[x].r].l = x;
  }
  bool Dance() {
    if (!e[0].r) return 1;
    int x = e[0].r;
    for (int i = x; i; i = e[i].r) (s[x] > s[i]) && (x = i);
    Delete(x);
    for (int i = e[x].d; i != x; i = e[i].d) {
      st[++t] = e[i].i;
      for (int j = e[i].r; j != i; j = e[j].r) Delete(e[j].j);
      if (Dance()) return 1;
      for (int j = e[i].l; j != i; j = e[j].l) Recover(e[j].j);
      --t;
    }
    Recover(x);
    return 0;
  }
} s;

int t, a[16][16];
char ch;

int main() {
  int _ = 0;
  while (cin >> ch) {
    if (_++) cout << endl;
    s.Build(kR, kC);
    for (int i = 0, c = 0; i < 16; ++i) {
      for (int j = 0; j < 16; ++j) {
        if (i || j) cin >> ch;
        a[i][j] = ch == '-' ? 0 : ch - 'A' + 1;
        for (int k = 1; k <= 16; ++k) {
          if (a[i][j] && a[i][j] != k) continue;
          int b = i / 4 * 4 + j / 4, d = i * 256 + j * 16 + k;
          s.Insert(d, i * 16 + k), s.Insert(d, j * 16 + k + 256), s.Insert(d, b * 16 + k + 256 * 2), s.Insert(d, i * 16 + j + 256 * 3 + 1);
        }
      }
    }
    s.Dance();
    for (int i = 1; i <= s.t; ++i) {
      int x = s.st[i] - 1;
      a[x / 16 / 16][x / 16 % 16] = x % 16 + 1;
    }
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 16; ++j) {
        cout << char(a[i][j] + 'A' - 1);
      }
      cout << endl;
    }
  }
  return 0;
}
/*

*/