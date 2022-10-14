#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif
#define int long long

using namespace std;

typedef long long ll;

const int kMaxN = 25;

int T, n, cnt;
int a[kMaxN], vis[kMaxN], b[kMaxN];
ll c, f[kMaxN][kMaxN][kMaxN];

void prework() {
  f[2][1][2] = f[2][2][1] = 1;
  ll sum = 0;
  for (int i = 3; i <= 20; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = 1; k <= i; ++k) {
        if (j == k) continue ;
        int sj = j, sk = k;
        if (j < k) --sk;
        for (int s = 1; s <= i; ++s) {
          if (j == s || k == s) continue ;
          int ss = s;
          if (!(k > j && k > s || k < j && k < s)) continue ;
          if (j < s) --ss;
          f[i][j][k] += f[i - 1][sk][ss];
        }
      }
    }
  }
}

bool check(int x, int y, int z) {
  return y > x && y > z || y < x && y < z;
}

bool check(int x, int y) {
  return check(a[n - 2], x, y) && check(a[n - 3], a[n - 2], x);
}

signed main() {
  freopen("wave.in", "r", stdin);
  freopen("wave.out", "w", stdout);
  prework();
  cin >> T;
  while (T--) {
    cin >> n >> c;
    memset(vis, 0, sizeof(vis));
    if (n == 1) {
      cout << "1" << endl;
      continue ;
    }
    if (n == 2) {
      if (c == 1) cout << "1 2" << endl;
      else cout << "2 1" << endl;
      continue ;
    }
    for (int nw = 1; nw <= n - 2; ++nw) {
      int t = n - nw + 1, idx, cc = c;
      for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue ;
        if (nw >= 3 && !check(a[nw - 2], a[nw - 1], i)) continue ;
        for (int j = 1; j <= n; ++j) {
          if (vis[i] || vis[j]) continue ;
          if (i == j || i == a[nw - 1] || j == a[nw - 1] 
         || nw != 1 && !(i > a[nw - 1] && i > j || i < a[nw - 1] && i < j)) continue ;
          int si = i, sj = j;
          for (int k = 1; k < nw; ++k) {
            if (a[k] < i) --si;
            if (a[k] < j) --sj;
          }
          cc -= f[t][si][sj];
        }
        if (cc <= 0) {
          idx = i;
          break ;
        }
      }
      a[nw] = idx;
      for (int i = 1; i < idx; ++i) {
        if (vis[i]) continue ;
        // if (nw == 4) debug(i);
        if (nw >= 3 && !check(a[nw - 2], a[nw - 1], i)) continue ;
        for (int j = 1; j <= n; ++j) {
          if (vis[i] || vis[j]) continue ;
          if (i == j || i == a[nw - 1] || j == a[nw - 1]
         || nw != 1 && !(i > a[nw - 1] && i > j || i < a[nw - 1] && i < j)) continue ;
          // if (nw == 4) debug(i, j);
          int si = i, sj = j;
          for (int k = 1; k < nw; ++k) {
            if (a[k] < i) --si;
            if (a[k] < j) --sj;
          }
          c -= f[t][si][sj];
        }
      }
      // debug(nw, c);
      vis[idx] = 1;
    }
    // debug(f[3][1][3]);
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) b[++cnt] = i;
    }
    if (c == 1) {
      if (check(b[1], b[2])) {
        a[n - 1] = b[1], a[n] = b[2];
      } else {
        a[n - 1] = b[2], a[n] = b[1];
      }      
    } else {
      a[n - 1] = b[2], a[n] = b[1];
    }
    for (int i = 1; i <= n; ++i) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}