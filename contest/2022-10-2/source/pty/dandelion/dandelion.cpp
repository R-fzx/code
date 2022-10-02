#include <fstream>
#include <unordered_map>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 4e4 + 1;

ifstream fin("dandelion.in");
ofstream fout("dandelion.out");

struct T {
  unordered_map<int, int> c;
  int x;
} t[kMaxN * 4];

int a[kMaxN], n, m, gl, gr, x, xc;

int G(unordered_map<int, int> &c, int v) {
  return c.find(v) == c.end() ? 0 : c[v];
}

void Build(int i, int l, int r) {
  for (int j = l; j <= r; j++) {
    t[i].c[a[j]]++;
    if (t[i].c[a[j]] > G(t[i].c, t[i].x) ||
        t[i].c[a[j]] == G(t[i].c, t[i].x) && a[j] < t[i].x) {
      t[i].x = a[j];
    }
  }
  if (l < r) {
    int m = (l + r) / 2;
    Build(i * 2, l, m);
    Build(i * 2 + 1, m + 1, r);
  }
}

int Count(int i, int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) {
    return G(t[i].c, v);
  }
  int ans = 0, m = (l + r) / 2;
  if (tl <= m) {
    ans += Count(i * 2, l, m, tl, min(m, tr), v);
  }
  if (tr > m) {
    ans += Count(i * 2 + 1, m + 1, r, max(tl, m + 1), tr, v);
  }
  return ans;
}

void Find(int i, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    int shit = Count(1, 1, n, gl, gr, t[i].x);
    if (shit > xc || shit == xc && t[i].x < x) {
      x = t[i].x, xc = shit;
    }
    return;
  }
  int m = (l + r) / 2;
  if (tl <= m) {
    Find(i * 2, l, m, tl, min(tr, m));
  }
  if (tr > m) {
    Find(i * 2 + 1, m + 1, r, max(tl, m + 1), tr);
  }
}

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  Build(1, 1, n);

  for (int i = 1; i <= m; i++) {
    fin >> gl >> gr;
    gl = (gl + x - 1) % n + 1, gr = (gr + x - 1) % n + 1;
    if (gl > gr) {
      swap(gl, gr);
    }
    xc = 0;
    Find(1, 1, n, gl, gr);
    fout << x << '\n';
  }
  return 0;
}