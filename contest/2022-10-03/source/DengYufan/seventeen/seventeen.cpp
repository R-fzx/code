#include <iostream>
#define LL long long

using namespace std;

LL n, a[2][201], f[201][100001];

LL M(bool p) {
  LL ans = 1145141919810;
  fill(&f[0][0], &f[200][100000] + 1, 1145141919810), f[0][50000] = 0;
  for (LL i = 1; i <= n; i++) {
    for (LL j = -200 * i; j <= 200 * i; j++) {
      f[i][j + 50000] = min(f[i][j + 50000],
                            min(f[i - 1][j - a[p][i] + 50000] + a[p][i] * (j - a[p][i]),
                                f[i - 1][j + a[p][i] + 50000] - a[p][i] * (j + a[p][i])));
    }
  }
  for (LL i = -200 * n; i <= 200 * n; i++) {
    ans = min(ans, f[n][i + 50000]);
  }
  return ans;
}

int main() {
  freopen("seventeen.in", "r", stdin);
  freopen("seventeen.out", "w", stdout);
  cin >> n;
  for (LL i = 1; i <= n; i++) {
    cin >> a[0][i] >> a[1][i];
  }
  cout << M(0) + M(1) << ".00";
  return 0;
}
