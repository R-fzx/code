#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, a[N], b[N];
double ans;

int main() {
  freopen("vote.in", "r", stdin);
  freopen("vote.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, (double)b[i] / n);
  }
  cout << setprecision(4) << fixed << ans;
  return 0;
}