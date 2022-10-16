#include <algorithm>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

constexpr int N = 2005, M = 105;

int n, k, m, ans;

int dp[M][M][N][2];

struct AC {
  int x, s, t;

  bool operator<(const AC& x) const { return this->x < x.x; }

  int dist(const AC& x) { return abs(this->x - x.x); }
} a[M];

void dfs(int l, int r, int t, int c, int s) {
  int i = c ? l : r;
  if (t < a[i].t) {
    s += a[i].s;
  }
  if (s <= dp[l][r][t][c]) {
    return;
  } else {
    dp[l][r][t][c] = s;
  }
  ans = max(ans + 1, s) - 1;
  if (l > 1) {
    dfs(l - 1, r, t + a[l - 1].dist(a[i]), 1, s);
  }
  if (r < m) {
    dfs(l, r + 1, t + a[r + 1].dist(a[i]), 0, s);
  }
}

int main() {
  freopen("go.in", "r", stdin);
  freopen("go.out", "w", stdout);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].x >> a[i].s >> a[i].t;
  }
  sort(a + 1, a + m + 1);
  int s;
  for (s = 0; s <= m && a[s].x < k; s++) {
  }
  for (int i = ++m; i > s; i--) {
    a[i] = a[i - 1];
  }
  a[s] = {k, 0, (int)1e9};
  dfs(s, s, 0, 0, 1);
  cout << ans;
  return 0;
}