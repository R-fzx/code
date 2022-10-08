#include <iostream>
#define LL long long

using namespace std;

const LL kMod = 1e9 + 7;
LL n, ans, a[100001], f[2][100001];

int main() {
  cin >> n;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[0][0] = f[1][n + 1] = 1;
  for (LL i = 1; i <= n; i++) {
    for (LL j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        f[0][i] = (f[0][i] + f[0][j]) % kMod;
      }
    }
  }
  for (LL i = n; i >= 1; i--) {
    for (LL j = n + 1; j > i; j--) {
      if (a[j] < a[i]) {
        f[1][i] = (f[1][i] + f[1][j]) % kMod;
      }
    }
  }
  for (LL i = 2; i < n; i++) {
    ans = (ans + f[0][i] * f[1][i] % kMod) % kMod;
  }
  cout << ans * 500000004 % kMod;
  return 0;
}
