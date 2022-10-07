#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN][2];
long long sum[MAXN];

int main() {
  freopen("tanabata.in", "r", stdin);
  freopen("tanabata.out", "w", stdout);
  int n, m, t, x, y;
  long long ans = 0;
  cin >> n >> m >> t;
  for (int i = 0; i < t; ++i) {
    cin >> x >> y;
    ++a[x][0], ++a[y][1];
  }
  if (t % n == 0) {
    int x = t / n;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + a[i][0] - x;
    }
    sort(sum + 1, sum + n + 1);
    int mid = n >> 1;
    for (int i = 1; i <= n; ++i) {
      ans += abs(sum[mid] - sum[i]);
    }
  }
  if (t % m == 0) {
    int x = t / m;
    for (int i = 1; i <= m; ++i) {
      sum[i] = sum[i - 1] + a[i][1] - x;
    }
    sort(sum + 1, sum + m + 1);
    int mid = n >> 1;
    for (int i = 1; i <= m; ++i) {
      ans += abs(sum[mid] - sum[i]);
    }
  }
  if (t % n == 0 && t % m == 0) {
    cout << "both " << ans;
  } else if (t % n == 0) {
    cout << "row " << ans;
  } else if (t % m == 0) {
    cout << "column " << ans;
  } else {
    cout << "impossible";
  }
  return 0;
}