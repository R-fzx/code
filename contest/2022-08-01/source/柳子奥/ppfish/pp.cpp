
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
int n, k, len;
int c[kMaxN], b[kMaxN], lst[kMaxN];
db p, f[kMaxK][kMaxN], g[kMaxN], ans[kMaxN];
ull hs[kMaxL], pw[kMaxLL];
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
  cin >> p >> k;
  // for (int i = 1; i <= n; ++i) {
  //   cerr << "***" << c[i] << endl;
  // }
  for (int i = 1; i <= n; ++i) {
    a[i] = Node(c[i], i);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) {
    for (int j = i - 1; j; --j) {
      if (a[i].c != a[j].c) {
        lst[i] = j;
        break ;
      }
    }
  }
  for (int i = 1; i <= n; ++i) f[0][i] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      f[i][j] = f[i - 1][j] * (1 - f[i - 1][lst[j]]) * p + f[i - 1][lst[j]];
    }
  }
  // for (int i = 1; i <= m; ++i) {
  //   cout << 1 - g[i] << endl;
  // }
  for (int i = 1; i <= n; ++i) {
    ans[a[i].idx] = f[k][i];
  }
  for (int i = 1; i <= n; ++i) {
    cout << fixed << setprecision(3) << ans[i] << ' ';
  }
  return 0;
}
/*
5
he
she
her
hers
his
hershe
0.31 2
*/