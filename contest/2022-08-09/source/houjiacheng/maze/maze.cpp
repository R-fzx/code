# include <stdio.h>
# include <vector>
# include <algorithm>

using namespace std;

int n, m, X;
int c[22][22];
vector<int> dpl[22][22];
vector<int> dpr[22][22];
vector<pair<int, int> > asl[22];
vector<pair<int, int> > asr[22];


int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &X);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", c[i] + j);
    }
  }
  dpl[0][1].push_back(0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(m, n - i + 1); j++) {
      if (c[i][j] == 0) {
        continue;
      }
      for (auto k : dpl[i - 1][j]) {
        dpl[i][j].push_back(k ^ c[i][j]);
      }
      for (auto k : dpl[i][j - 1]) {
        dpl[i][j].push_back(k ^ c[i][j]);
      }
      if (j == n - i + 1) {
        if (dpl[i][j].size() == 0) {
          continue;
        }
        sort(dpl[i][j].begin(), dpl[i][j].end());
        asl[j].push_back(make_pair(dpl[i][j][0], 1));
        for (int k = 1; k < dpl[i][j].size(); k++) {
          if (dpl[i][j][k] == dpl[i][j][k - 1]) {
            ++asl[j][asl[j].size() - 1].second;
          } else {
            asl[j].push_back(make_pair(dpl[i][j][k], 1));
          }
        }
      }
    }
  }
  dpr[n + 1][m].push_back(0);
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= max(1, n - i + 1); j--) {
      if (c[i][j] == 0) {
        continue;
      }
      for (auto k : dpr[i + 1][j]) {
        dpr[i][j].push_back(k ^ c[i][j]);
      }
      for (auto k : dpr[i][j + 1]) {
        dpr[i][j].push_back(k ^ c[i][j]);
      }
      if (j == n - i + 1) {
        if (dpr[i][j].size() == 0) {
          continue;
        }
        sort(dpr[i][j].begin(), dpr[i][j].end());
        asr[j].push_back(make_pair(dpr[i][j][0] ^ c[i][j], 1));
        for (int k = 1; k < dpr[i][j].size(); k++) {
          if (dpr[i][j][k] == dpr[i][j][k - 1]) {
            ++asr[j][asl[j].size() - 1].second;
          } else {
            asl[j].push_back(make_pair(dpr[i][j][k] ^ c[i][j], 1));
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= min(n, m); i++) {
    for (auto j : asl[i]) {
      int x = X ^ j.first;
      int l = 0, r = asr[i].size() - 1;
      while (l < r) {
        int mid = ((l + r) >> 1);
        if (asr[i][mid].first < x) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      if (asr[i][l].first == x) {
        ans += 1ll * j.second * asr[i][l].second;
      }
    }
  }
  printf("%lld", ans);
}
/*

3 3 1
1 1 5
2 3 1
0 4 5

*/