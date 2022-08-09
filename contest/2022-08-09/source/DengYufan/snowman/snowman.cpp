#include <iostream>
#define LL long long

using namespace std;

int n, ans, a[5001], l[5001][5001];

int main() {
  freopen("snowman.in", "r", stdin);
  freopen("snowman.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int p = 1; p <= n; p++) {
    l[p][p] = n - p + 1;
    for (int i = 1; i < p; i++) {
      l[p][i] = l[i][p];
    }
    for (int i, j = 1, k = p + 1; k <= n; k++) {
      if (k < j) {
        if (j - k > l[p][k - i]) {
          l[p][k] = l[p][k - i];
          continue;
        }
        i = k;
      } else {
        i = k;
      }
      for (j = i; j <= n && a[j] - a[p + j - i] == a[i] - a[p]; j++) {
      }
      l[p][k] = j - i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans = max(ans, min(j - i, l[i][j]));
    }
  }
  cout << ans;
  return 0;
}
