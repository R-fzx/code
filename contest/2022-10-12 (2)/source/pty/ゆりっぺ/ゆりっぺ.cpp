#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;

ifstream fin("ゆりっぺ.in");
ofstream fout("ゆりっぺ.out");

const int kMaxS = 5e5 + 1, kMaxM = 1e5 + 1;

Pll operator+(Pll a, Pll b) { return {a.first + b.first, a.second + b.second}; };

struct S {
  LL v[4];
  bool t;
} s[kMaxS];

struct V {
  int fe, f, b;
  Pll v;
} v[kMaxM];

struct E {
  int y, c, n;
  Pll v;
} e[kMaxM];

Pll kInf = {-4e18, -4e18}, ans;
int l[kMaxS], shit, n, m = 1, c[3];

void AE(int x, int y, int c, LL v1, LL v2) {
  e[++m] = {y, c, v[x].fe, {v1, v2}};
  v[x].fe = m;
}

void AddE(int x, int y, int c, LL v1, LL v2) {
  AE(x, y, c, v1, v2), AE(y, x, 0, -v1, -v2);
}

bool F() {
  queue<int> q;
  for (int i = 2; i <= n; i++) {
    v[i].v = kInf;
  }
  for (q.push(1); !q.empty(); q.pop()) {
    int x = q.front();
    v[x].b = 0;
    for (int i = v[x].fe; i; i = e[i].n) {
      if (e[i].c) {
        int y = e[i].y;
        if (v[x].v + e[i].v > v[y].v) {
          v[y].v = v[x].v + e[i].v;
          v[y].f = i;
          if (!v[y].b) {
            v[y].b = 1, q.push(y);
          }
        }
      }
    }
  }
  return v[5].v != kInf;
}

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  fin >> shit;
  for (int i = 0; i <= 2; i++) {
    fin >> c[i];
    n += c[i];
    AddE(i + 2, 5, c[i], 0, 0);
  }
  for (int i = 1; i <= shit; i++) {
    fin >> s[i].v[0] >> s[i].v[1] >> s[i].v[2];
    s[i].v[3] = s[i].v[0] + s[i].v[1] + s[i].v[2];
    l[i] = i;
  }
  for (int o = 0; o <= 2; o++) {
    sort(l + 1, l + 1 + shit, [o](int i, int j) { return s[i].v[o] > s[j].v[o] || s[i].v[o] == s[j].v[o] && s[i].v[3] > s[j].v[3]; });
    for (int i = 1; i <= min(n, shit); i++) {
      s[l[i]].t = 1;
    }
  }
  n = 5;
  for (int i = 1; i <= shit; i++) {
    if (s[i].t) {
      ++n;
      AddE(1, n, 1, 0, s[i].v[3]);
      for (int j = 0; j <= 2; j++) {
        AddE(n, j + 2, 1, s[i].v[j], 0);
      }
    }
  }
  while (F()) {
    ans = ans + v[5].v;
    for (int i = 5, j; i != 1; i = e[j ^ 1].y) {
      j = v[i].f;
      e[j].c--, e[j ^ 1].c++;
    }
  }
  fout << ans.first << '\n'
       << ans.second;
  return 0;
}
