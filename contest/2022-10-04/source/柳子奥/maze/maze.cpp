#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

const int kMaxN = 1e4 + 5, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
const double kEps = 1e-6, kInf = 0x3f3f3f3f;

int T, n, m, ss, tt;
double L, dis[kMaxN];
int mz[kMaxN];
string s;
vector<pair<int, double>> G[kMaxN];
priority_queue<pair<double, int>> q;
bool vis[kMaxN];

void addE(int u, int v, double w) {
  G[u].emplace_back(v, w);
}

int getid(int x, int y) {
  return (x - 1) * m + y;
}

void init() {
  for (int i = 1; i <= n * m; ++i) {
    G[i].clear();
  }
  while (!q.empty()) q.pop();
}

void build(double v) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!mz[getid(i, j)]) continue ;
      for (int k = 0; k < 4; ++k) {
        int ti = i + dx[k], tj = j + dy[k];
        if (!mz[getid(ti, tj)]) continue ;
        if (k <= 1) {
          addE(getid(i, j), getid(ti, tj), v);
        } else {
          addE(getid(i, j), getid(ti, tj), 1);
        }
      }
    }
  }
}

double get(double x) {
  init(), build(x);
  fill(dis + 1, dis + 1 + n * m, kInf), fill(vis + 1, vis + 1 + n * m, 0);
  q.emplace(0, ss), dis[ss] = 0;
  while (!q.empty()) {
    auto nf = q.top(); q.pop();
    int u = nf.second;
    if (vis[u]) continue ;
    vis[u] = 1;
    for (auto p : G[u]) {
      int v = p.first; double w = p.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w, q.emplace(-dis[v], v);
      }
    }
  }
  // debug(x, dis[tt]);
  return dis[tt];
}

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> T;
  while (T--) {
    cin >> L >> n >> m; getchar();
    memset(mz, 0, sizeof(mz));
    for (int i = 1; i <= n; ++i) {
      getline(cin, s); s = " " + s;
      for (int j = 1; j <= m; ++j) {
        if (s[j] == '#') {
          mz[getid(i, j)] = 0;
        } else {
          mz[getid(i, j)] = 1;
          if (s[j] == 'S') {
            ss = getid(i, j);
            // debug("ss", i, j);
          } else if (s[j] == 'E') {
            tt = getid(i, j);
            // debug("tt", i, j);
          }
        }
      }
    }
    // debug(ss, tt);
    double l = 0, r = 10, res;
    while (l + kEps < r) {
      double mid = (l + r) / 2.0;
      if (get(mid) >= L) r = res = mid;
      else l = mid;
    }
    cout << fixed << setprecision(5) << res << endl;
  }
  return 0;
}