#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

ifstream fin("h.in");
ofstream fout("h.out");

const int kMaxN = 2e5 + 2;

struct P {
  int x, y;
  bool operator<(const P &_p) const { return y > _p.y; };
} p[kMaxN];

struct E {
  set<int> p, m;
  int l, r, h, b;
} e[kMaxN];

struct T {
  set<int> p, m;
} t[kMaxN * 4];

int l[kMaxN], n, m, k;
long long ans;

int GetR(int x) { return e[x].b == x ? x : e[x].b = GetR(e[x].b); }

void Insert(int i, int l, int r, int tar) {
  t[i].p.insert(p[tar].y + tar);
  t[i].m.insert(p[tar].y - tar);
  if (l < r) {
    int m = (l + r) / 2;
    if (p[tar].x <= m) {
      Insert(i * 2, l, m, tar);
    } else {
      Insert(i * 2 + 1, m + 1, r, tar);
    }
  }
}

void C(set<int> &a, set<int> &b, int v) {
  if (a.size() && !b.size()) {
    auto j = b.rbegin();
    int c= b.size();
    for (int i : a) {
      for (; j != b.rend() && i + *j > v; j++, c--) {
      }
      ans = ans + c;
    }
  }
}

void Merge(set<int> &a, set<int> &b) {
  for (auto i : a) {
    b.insert(i);
  }
  a.clear();
}

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  fin >> n >> k;
  for (int i = 1; i <= n; i++) {
    fin >> e[i].h;
    l[i] = i;
  }
  fin >> m;
  for (int i = 1; i <= m; i++) {
    fin >> p[i].x >> p[i].y;
    Insert(1, 1, n, i);
  }

  sort(l + 1, l + 1 + n, [](int i, int j) { return e[i].h > e[j].h; });
  sort(p + 1, p + 1 + m);
  for (int i = 1, j = 1; i <= n || j <= m;) {
    if (j > m || e[l[i]].h >= p[j].y) {
      int x = l[i];
      if (!e[x - 1].b && !e[x + 1].b) {
        e[x].b = e[x].l = e[x].r = 1;
      } else if (e[x - 1].b && e[x + 1].b) {
        int l = GetR(x - 1), r = GetR(x + 1);
        C(e[l].m, e[r].p, k + 2 * e[x].h);
        if (e[l].r - e[l].l < e[r].r - e[r].l) {
          Merge(e[l].m, e[r].m), Merge(e[l].p, e[r].p);
          e[l].b = r, e[r].l = e[l].l;
        } else {
          Merge(e[r].m, e[l].m), Merge(e[r].p, e[l].p);
          e[r].b = l, e[l].r = e[r].r;
        }
      }
      i++;
    } else {
      
      j++;
    }
  }

  return 0;
}