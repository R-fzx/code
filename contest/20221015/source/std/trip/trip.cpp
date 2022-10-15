#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("trip.in");
ofstream fout("trip.out");

const int kMaxN = 5e4 + 1, kMaxM = 1e5 + 1, kMaxV = 15000, kV = 200;

struct E {
  int x, y, c;
  bool operator<(const E &_e) const { return c < _e.c; }
} e[kMaxM];

int b[kMaxN], r[kMaxN], p[kMaxN], s, t, m, n, le, ri, mi, ansl, ansr;

int R(int x) { return r[x] == x ? x : r[x] = R(r[x]); }

bool C() {
  for (int i = 1; i <= n; i++) {
    r[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    if (e[i].c >= mi * kV) {
      int x = R(e[i].x), y = R(e[i].y);
      r[x] = y;
      if (R(s) == R(t)) {
        ansl = mi, ansr = (e[i].c + kV - 1) / kV;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  fin >> t >> m;
  for (int i = 1; i <= m; i++) {
    fin >> e[i].x >> e[i].y >> e[i].c;
  }
  for (int i = 1, c, d; i <= t; i++) {
    for (fin >> c, n += c; c; c--) {
      fin >> d;
      b[d] = i;
    }
  }
  for (int i = 1; i <= t; i++) {
    fin >> p[i];
  }
  fin >> s >> t;
  for (int i = 1; i <= m; i++) {
    e[i].c *= p[b[e[i].x]] + p[b[e[i].y]];
  }
  sort(e + 1, e + 1 + m);
  for (le = 0, ri = kMaxV; le <= ri;) {
    mi = (le + ri) / 2;
    if (C()) {
      le = mi + 1;
    } else {
      ri = mi - 1;
    }
  }
  fout << ansl << ' ' << ansr;
  return 0;
}