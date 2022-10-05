# include <bits/stdc++.h>

using namespace std;

long long ans, x[1010], y[1010];
int n;

int main() {
  freopen("scalar.in", "r", stdin);
  freopen("scalar.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", x + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", y + i);
  }
  sort(x + 1, x + 1 + n);
  sort(y + 1, y + 1 + n);
  for (int i = 1; i <= n; i++) {
    ans += x[i] * y[n + 1 - i];
  }
  printf("%lld\n", ans);
}
/*

5
1 2 3 4 5
1 0 1 0 1

*/