#include <iostream>
#define debug cerr << "QwQ" << endl

using namespace std;

const int kN = 2916, kR = 729, kC = 324;

struct S {
  struct E {
    int u, d, l, r, i, j;
  } e[kN + kR + kC + 1];
  int _c, f[kR + 1], s[kC + 1], st[kR + 1], t;

  void Build(int r, int c) {
    for (int i = 0; i <= c; ++i) e[i] = {i, i, i - 1, i + 1, 0, 0};
    e[0].l = c, e[c].r = 0, _c = c;
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
  bool Dance(int d) {
    if (!e[0].r) return 1;
    int x = e[0].r;
    for (int i = x; i; i = e[i].r) (s[x] > s[i]) && (x = i);
    Delete(x);
    for (int i = e[x].d; i != x; i = e[i].d) {
      st[++t] = e[i].i;
      for (int j = e[i].r; j != i; j = e[j].r) Delete(e[j].j);
      if (Dance(d + 1)) return 1;
      for (int j = e[i].l; j != i; j = e[j].l) Recover(e[j].j);
      --t;
    }
    Recover(x);
    return 0;
  }
} s;

int a[9][9];

int main() {
  // freopen("P1784.in", "r", stdin);
  // freopen("P1784.out", "w", stdout);
  // freopen("P1784.log", "w", stderr);
  s.Build(kR, kC);
  debug;
  for (int i = 0, c = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cin >> a[i][j];
      for (int k = 1; k <= 9; ++k) {
        if (a[i][j] && a[i][j] != k) continue;
        int b = i / 3 * 3 + j / 3, d = i * 81 + j * 9 + k;
        s.Insert(d, i * 9 + k), s.Insert(d, j * 9 + k + 81), s.Insert(d, b * 9 + k + 81 * 2), s.Insert(d, i * 9 + j + 81 * 3 + 1);
      }
    }
  }
  debug;
  s.Dance(0);
  debug;
  cerr << s.t << endl;
  for (int i = 1; i <= s.t; ++i) {
    int x = s.st[i] - 1;
    a[x / 9 / 9][x / 9 % 9] = x % 9 + 1;
  }
  debug;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
/*

*/