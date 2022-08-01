#pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef double db;

const int kMaxN = 25, kMaxK = 1e3 + 5, kMaxL = 205, kMaxLL = 1e6 + 5;

struct Node {
  int c, idx;

  Node() {}
  Node(int _c, int _idx) : c(_c), idx(_idx) {}
  ~Node() {}

  friend bool operator < (const Node &n1, const Node &n2) {
    return n1.c < n2.c;
  }
} a[kMaxN] ;

unordered_map<ull, int> mp;
int n, m, k, len;
int c[kMaxN], b[kMaxN];
db p, f[kMaxK][kMaxN], g[kMaxN], ans[kMaxN];
ull hs[kMaxLL], pw[kMaxLL];
string s[kMaxN], t;

ull get(string s) {
  ull ret = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    ret = 13331 * ret + s[i];
  }
  return ret;
}

ull getHash(int l, int r) {
  return hs[r] - hs[l - 1] * pw[r - l + 1];
}

int main() {
  freopen("ppfish.in", "r", stdin);
  freopen("ppfish.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    mp[get(s[i])] = i;
  }
  cin >> t;
  // cerr << "***" << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  len = t.size(); t = " " + t;
  pw[0] = 1;
  for (int i = 1; i <= len; ++i) 
    pw[i] = pw[i - 1] * 13331;
  for (int i = 1; i <= len; ++i) {
    hs[i] = hs[i - 1] * 13331 + t[i];
  }
  for (int l = 1; l <= 20; ++l) {
    for (int i = 1; i + l - 1 <= len; ++i) {
      int j = i + l - 1;
      ++c[mp[getHash(i, j)]];
    }
  }
  // cerr << "***" << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  cin >> p >> k;
  // for (int i = 1; i <= n; ++i) {
  //   cerr << "***" << c[i] << endl;
  // }
  for (int i = 1; i <= n; ++i) {
    a[i] = Node(c[i], i);
    b[i] = c[i];
  }
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  m = unique(b + 1, b + 1 + n) - (b + 1);
  for (int i = 1; i <= n; ++i) {
    a[i].c = lower_bound(b + 1, b + 1 + m, a[i].c) - b;
  }
  f[0][0] = 1;
  // cerr << "***" << m << endl;
  for (int i = 1; i <= k; ++i) {
    f[i][0] = f[i - 1][0] * p;
    for (int j = 1; j < m; ++j) {
      f[i][j] = f[i - 1][j] * p + f[i - 1][j - 1] * (1.0 - p);
    }
    f[i][m] = f[i - 1][m - 1] * (1 - p) + f[i - 1][m];
  }
  // cerr << "***" << f[2][1] << endl;
  // for (int i = 0; i <= m; ++i) {
  //   cerr << "***" << f[k][i] << endl;
  // }
  for (int i = 1; i <= m; ++i) {
    // cerr << f[k][i] << endl;
    for (int j = i - 1; ~j; --j) {
      g[i] += f[k][j];
    }
    // ans[a[i].idx] = f[k][i];
    // cerr << "***" << g[i] << endl;
  }
  // for (int i = 1; i <= m; ++i) {
  //   cout << 1 - g[i] << endl;
  // }
  for (int i = 1; i <= n; ++i) {
    ans[a[i].idx] = g[a[i].c];
  }
  for (int i = 1; i <= n; ++i) {
    cout << fixed << setprecision(3) << ans[i] << ' ';
  }
  // cerr << "***" << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}
/*
f[i][j]=f[i-1][j] * (1 - f[i-1][lst[j]]) * p + f[i - 1][lst[j]]
*/