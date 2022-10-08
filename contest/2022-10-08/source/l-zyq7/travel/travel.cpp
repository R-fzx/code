#include <bits/stdc++.h>
using namespace std;
int n, m, fa[209], d[209];
bool ach[209][209], w[209][209], a[209][209];
vector<int> g[209], v[209], ans;
inline int read() {
  int r(0);
  char ch(getchar());
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r;
}
inline void write(int x) {
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline int find(int x) {
  return fa[x] == x ? x : find(fa[x]);
}
inline void add(int a, int b) {
  swap(a, b);
  ach[a][b] = true;
  fa[find(b)] = find(a);
}
inline void _add(int a, int b) {
  g[a].push_back(b), g[b].push_back(a);
  w[a][b] = true, w[b][a] = true;
  d[a]++, d[b]++;
}
inline bool check(vector<int> v, int j) {
  int tot(0), b[209];
  while (++tot) {
    bool c(false);
    for (int i(0); i < v.size(); i++) b[v[i]] = tot;
    for (int i(0); i < v.size(); i++) {
      for (int j(0); j < g[v[i]].size() && d[v[i]] >= j - 1; j++) {
        if (b[g[v[i]][j]] != tot) {
          d[v[i]]--, c = true;
        }
      }
    }
    if (!c) break;
    vector<int> cur;
    for (int i(0); i < v.size(); i++) {
      if (d[v[i]] >= j - 1) {
        cur.push_back(v[i]);
      }
    }
    v = cur;
  }
  return v.size() >= j;
}
int main() {
  freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout);
  n = read(), m = read();
  for (int i(1); i <= n; i++) fa[i] = i;
  for (int i(0); i < m; i++) {
    add(read(), read());
  }
  for (int k(1); k <= n; k++) {
    for (int i(1); i <= n; i++) {
      for (int j(1); j <= n; j++) {
        if (ach[i][j] || !ach[i][k] || !ach[k][j]) continue;
        ach[i][j] = true;
      }
    }
  }
  for (int i(1); i <= n; i++) {
    v[find(i)].push_back(i);
  }
  for (int i(1); i <= n; i++) {
    if (!v[i].size()) continue;
    // cout << i << '\n';
    //  puts("\\\\");
    for (int j(0); j < v[i].size(); j++) {
      // cout << i << ' ' << v[i][j] << '\n';
      for (int k(j + 1); k < v[i].size(); k++) {
        if (!ach[v[i][j]][v[i][k]] && !ach[v[i][k]][v[i][j]]) _add(v[i][j], v[i][k]);
      }
    }
    int j(1), cur;
    for (; j <= v[i].size() + 1; j++) {
      vector<int> w;
      for (int k(0); k < v[i].size(); k++) {
        if (d[v[i][k]] >= j - 1) w.push_back(v[i][k]);
      }
      if (w.size() < j) break;
      if (!check(w, j)) break;
    }
    j--;
    // cout << j << '\n';
    for (int k(0); k < v[i].size(); k++) {
      if (d[v[i][k]] >= j - 1) {
        cur = v[i][k];
        break;
      }
    }
    ans.push_back(cur);
    for (int k(0); k < g[cur].size() && j; k++) {
      if (d[g[cur][k]] >= j - 1) ans.push_back(g[cur][k]), j--;
    }
  }
  write(ans.size()), puts("");
  sort(ans.begin(), ans.end());
  for (int i(0); i < ans.size(); i++) {
    write(ans[i]), putchar(' ');
  }
  // cout << '\n'
  //      << clock();
  return 0;
}