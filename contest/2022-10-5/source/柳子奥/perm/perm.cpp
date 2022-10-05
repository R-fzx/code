#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#define pass 114514
#endif

#define int long long

using namespace std;

typedef __int128 i128;

string s;
int len, ans, tot, nw, a[55], c[10], b[105];

int A(int x) {
  int cc = 0; i128 ret = 1ll;
  tot = 0, nw = 1;
  for (int i = 1; i < 10; ++i) {
    cc += c[i];
    for (int j = 1; j <= c[i]; ++j) {
      b[++tot] = j;
    }
  }
  if (x < cc) return 0;
  for (int i = 1; i <= cc; ++i, --x) {
    ret *= x;
    for (; nw <= tot && ret % b[nw] == 0; ret /= b[nw++]) {}
  }
  return (int)ret;
}

int check() {
  for (int i = 1; i < 10; ++i) {
    if (c[i]) return 0;
  }
  return 1;
}

int dfs(int nw, bool lim) {
  if (nw == len + 1) return check();
  if (!lim) return A(len - nw + 1);
  int ret = 0;
  for (int i = 0; i <= a[nw]; ++i) {
    if (i && !c[i]) continue ;
    --c[i];
    if (i < a[nw]) ret += dfs(nw + 1, 0);
    else ret += dfs(nw + 1, 1);
    ++c[i];
  }
  return ret;
}

signed main() {
  freopen("perm.in", "r", stdin);
  freopen("perm.out", "w", stdout);
  cin >> s;
  len = s.size(), s = "#" + s;
  for (int i = 1; i <= len; ++i) {
    a[i] = s[i] - '0';
    if (a[i]) ++c[a[i]];
  }
  cout << dfs(1, 1) - 1 << endl;
  return 0;
}