#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#define pass 114514
#endif

using namespace std;

const int kMaxN = 2505;
const pair<int, int> kDir[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                  {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int n, st, ans = 1e9;
string s;
int a[kMaxN], dis[kMaxN];
bool vis[kMaxN];
vector<pair<int, int>> G[kMaxN];
priority_queue<pair<int, int>> q;

void addE(int u, int v, int w) {
  G[u].emplace_back(v, w);
}

string work(string s) {
  string ret = "";
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == '-' || s[i] == 'X' || s[i] == '@' || s[i] == '*') {
      ret += s[i];
    }
  }
  return ret;
}

int getid(int x, int y) {
  return (x - 1) * n + y;
}

void init() {
  for (int i = 1; i <= n * n; ++i) {
    G[i].clear(), dis[i] = 1e9, vis[i] = 0;
  }
  while (!q.empty()) q.pop();
}

void build(int x) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int u = getid(i, j);
      if (a[u] == 2) continue ;
      for (int k = 0; k < 8; ++k) {
        int ti = i + kDir[k].first, tj = j + kDir[k].second;
        if (ti < 1 || ti > n || tj < 1 || tj > n) continue ;
        if (a[getid(ti, tj)] == 2) continue ;
        addE(u, getid(ti, tj), (k == x ? 3 : 1));
      }
    }
  }
}

int get(int x) {
  init(), build(x);
  dis[st] = 0, q.emplace(0, st);
  while (!q.empty()) {
    auto nt = q.top(); q.pop();
    int u = nt.second;
    if (vis[u]) continue ;
    vis[u] = 1;
    for (auto p : G[u]) {
      int v = p.first, w = p.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w, q.emplace(-dis[v], v);
      }
    }
  }
  int ret = 1e9;
  for (int i = 1; i <= n * n; ++i) {
    if (a[i] == 3) ret = min(ret, dis[i]);
  }
  return (ret == 1e9 ? -1 : ret);
}

int main() {
  freopen("desert.in", "r", stdin);
  freopen("desert.out", "w", stdout);
  cin >> n; getchar();
  for (int i = 1; i <= n; ++i) {
    getline(cin, s);
    s = work(s);
    s = "#" + s;
    for (int j = 1; j <= n; ++j) {
      if (s[j] == 'X') {
        a[getid(i, j)] = 2;
      } else {
        a[getid(i, j)] = 1;
        if (s[j] == '@') {
          st = getid(i, j);
        } else if (s[j] == '*') {
          a[getid(i, j)] = 3;
        }
      }
    }
  }
  ans = -1;
  for (int i = 0; i < 8; ++i) {
    ans = max(ans, get(i));
  }
  cout << (ans == 1e9 ? -1 : ans) << endl;
  return 0;
}