#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;

inline void r(int &s) {
  s = 0;
  int c(getchar());
  while (c < 48 || c > 57) c = getchar();
  while (c > 47 && c < 58) s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
}

inline void w(int x) {
  if (x > 9) w(x / 10);
  putchar(x % 10 + 48);
} 

vector<int> a[MAXN];
vector<int> b[MAXN];
int c[MAXN];

bool f[MAXN][MAXN];
bool f1[MAXN];
int anss[MAXN];

void dfs(int x, int s) {
  if (f[s][x]) {
    return;
  }
  f[s][x] = 1;
  for (int i = 0; i < a[x].size(); ++i) {
    dfs(a[x][i], s);
  }
}

void dfs1(int x, int cl) {
  if (c[x]) {
    return;
  }
  c[x] = cl;
  for (int i = 0; i < b[x].size(); ++i) {
    dfs1(b[x][i], cl);
  }
}

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  int n, m, ans = 0, cnt, cntt;
  r(n), r(m);
  for (int i = 0, u, v; i < m; ++i) {
    r(u), r(v);
    a[u].push_back(v);
    b[u].push_back(v);
    b[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    dfs(i, i);
  }
  int cntc = 1;
  for (int i = 1; i <= n; ++i) {
    if (c[i] == 0) {
      dfs1(i, cntc);
      ++cntc;
    }
  }
  for (int cl = 1; cl < cntc; ++cl) {
    int maxx = -114514;
    for (int i = 1; i <= n; ++i) {
      if (c[i] == cl) {
        cnt = 1;
        for (int j = 1; j <= n; ++j) {
          if (c[j] == cl) {
            f1[j] = f[i][j] | f[j][i];
            cnt += !f1[j];
          }
        }
        if (cnt > maxx) {
          maxx = cnt;
          cntt = ans;
          anss[cntt++] = i;
          for (int j = 1; j <= n; ++j) {
            if (c[j] == cl && !f1[j]) {
              anss[cntt++] = j;
            }
          }
        }
      }
    }
    ans += maxx;
  }
  w(ans), putchar(10);
  for (int i = 0; i < ans; ++i) {
    w(anss[i]), putchar(32);
  }
  return 0;
}