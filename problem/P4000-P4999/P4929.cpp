#include <iostream>

using namespace std;

const int kN = 501;

int n, m;

struct S {
  struct E {
    int u, d, l, r, i, j;
  } e[kN * 11];
  int _c, f[kN], s[kN], st[kN], t;

  void Build(int r, int c) {
    for (int i = 0; i <= c; ++i) e[i] = {i, i, i - 1, i + 1, 0, 0};
    e[0].l = c, e[c].r = 0, _c = c;
  }
  void Insert(int r, int c) {
    (++_c, !f[r]) && (f[r] = e[_c].r = _c), e[_c] = {c, e[c].d, f[r], e[f[r]].r, r, c}, e[c].d = e[e[c].d].u = e[f[r]].r = e[e[f[r]].r].l = _c, ++s[c];
  }
  void Delete(int x) {
    e[e[x].l].r = e[x].r, e[e[x].r].l = e[x].l;
    for (int i = e[x].d; i ^ x; i = e[i].d)
      for (int j = e[i].r; j ^ i; j = e[j].r) e[e[j].u].d = e[j].d, e[e[j].d].u = e[j].u, --s[e[j].j];
  }
  void Recover(int x) {
    for (int i = e[x].u; i ^ x; i = e[i].u)
      for (int j = e[i].l; j ^ i; j = e[j].l) e[e[j].u].d = e[e[j].d].u = j, ++s[e[j].j];
    e[e[x].l].r = e[e[x].r].l = x;
  }
  bool Dance() {
    if (!e[0].r) return 1;
    int x = e[0].r;
    for (int i = e[x].r; i; i = e[i].r) (s[x] > s[i]) && (x = i);
    Delete(x);
    for (int i = e[x].d; i ^ x; i = e[i].d) {
      st[++t] = e[i].i;
      for (int j = e[i].r; j ^ i; j = e[j].r) Delete(e[j].j);
      if (Dance()) return 1;
      for (int j = e[i].l; j ^ i; j = e[j].l) Recover(e[j].j);
      --t;
    }
    Recover(x);
    return 0;
  }
} solver;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m, solver.Build(n, m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j <= m; ++j) {
      cin >> x, x && (solver.Insert(i, j), 0);
    }
  }
  if (solver.Dance())
    for (int i = 1; i <= solver.t; ++i) cout << solver.st[i] << " ";
  else
    cout << "No Solution!";
  return 0;
}