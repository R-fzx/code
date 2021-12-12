#include <ctime>
#include <iostream>
#define LL long long
#define Pii pair<LL, LL>

using namespace std;

LL n, c, ans, f[1001], d[1001];
Pii a[1001][2], p[1001];

inline LL GetRoot(LL x) {
  return f[x] == x ? x : f[x] = GetRoot(f[x]);
}

inline LL Cross(Pii s, Pii x, Pii y) {
  return (x.first - s.first) * (y.second - s.second) - (y.first - s.first) * (x.second - s.second);
}

inline bool C(LL i, LL j) {
  LL num[1001] = {};
  for (LL k(1); k <= n; k++) {
    num[GetRoot(k)] += Cross(p[i], p[j], a[k][0]) * Cross(p[i], p[j], a[k][1]) <= 0 && Cross(a[k][0], a[k][1], p[i]) * Cross(a[k][0], a[k][1], p[j]) <= 0;
  }
  for (LL k(1); k <= n; k++) {
    if (num[k] & 1) {
      return 0;
    }
  }
  return 1;
}

int main() {
  freopen("crazy.in", "r", stdin);
  freopen("crazy.out", "w", stdout);
  cin >> n >> c;
  for (LL i(1); i <= n; i++) {
    cin >> a[i][0].first >> a[i][0].second >> a[i][1].first >> a[i][1].second;
    f[i] = i;
  }
  for (LL i(1); i <= c; i++) {
    cin >> p[i].first >> p[i].second;
  }
  for (LL i(1); i <= n; i++) {
    for (LL j(1); j <= n; j++) {
      if (a[i][0] == a[j][0] || a[i][0] == a[j][1] || a[i][1] == a[j][0] || a[i][1] == a[j][1]) {
        f[GetRoot(i)] = GetRoot(j);
      }
    }
  }
  for (LL i(1); i < c; i++) {
    for (LL j(i + 1); j <= c; j++) {
      if (C(i, j)) {
        d[i]++;
      }
    }
    ans = max(ans, d[i] + 1);
  }
  cout << ans;
  // cout << "Runtime:" << clock() / 1000.0 << "s\n";
  return 0;
}
