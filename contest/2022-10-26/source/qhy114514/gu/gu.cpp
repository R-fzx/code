#include <bits/stdc++.h>

using namespace std;

const int kM = 1e9 + 7;
const int kMaxN = 3001;

int n, m, k, t, ans;
int a[kMaxN], b[kMaxN];
int f[kMaxN], h[kMaxN], s[kMaxN];
bool shit[kMaxN << 1][kMaxN << 1];
map<int, int> mp;

int main() {
  ifstream cin("gu.in");
  ofstream cout("gu.out");
  
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!mp.count(a[i])) {
      mp[a[i]] = ++t;
    }
    a[i] = mp[a[i]];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    if (!mp.count(b[i])) {
      mp[b[i]] = ++t;
    }
    b[i] = mp[b[i]];
  }
  for (int i = 1, x, y; i <= k; i++) {
    cin >> x >> y;
    if (!mp.count(x) || !mp.count(y)) {
      continue;
    }
    x = mp[x], y = mp[y], shit[y][x] = 1;
  }
  s[0] = 1;
  for (int i = 1; i <= t; i++) {
    shit[i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (shit[a[i]][b[j]]) {
        h[j] = (h[j] + s[j]) % kM;
      }
    }
    for (int j = 1; j <= m; j++) {
      h[j] = (h[j] + h[j - 1]) % kM;
    }
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        f[j] = (f[j] + h[j - 1]) % kM;
      }
    }
    for (int j = 0; j <= m; j++) {
      s[j] = (s[j] + f[j]) % kM, f[j] = h[j] = 0;
    }
  }
  for (int j = 1; j <= m; j++) {
    ans = (ans + s[j]) % kM;
  }
  cout << ans << '\n';
  return 0;
}
