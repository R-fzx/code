#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <tuple>

#define db(x) cerr << #x << '=' << x << endl;
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define dbg debug("*** Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

using namespace std;

using ll = long long;

const int dx[] = {-1, 0}, dy[] = {0, -1};

unordered_map<ll, ll> f[25][25];
int n, m, x, k1, k2;
int a[25][25];

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> n >> m >> x;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  f[n][m][x ^ a[n][m]] = 1;
  for (int i = n; i; --i) {
    for (int j = m; j; --j) {
      // if (i == 1 && j == 1) break ;
      // db(i); db(j);
      for (int k = 0; k < 2; ++k) {
        int ti = i + dx[k], tj = j + dy[k];
        if (ti < 1 || ti > n || tj < 1 || tj > m) continue ;
        // db(f[i][j].size());
        for (auto x : f[i][j]) {
          // db(x.first);
          f[ti][tj][x.first ^ a[ti][tj]] += x.second;
        }
      }
    }
  }
  cout << f[1][1][0] << endl;
  return 0;
}