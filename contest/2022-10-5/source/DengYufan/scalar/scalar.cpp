#include <algorithm>
#include <iostream>
#define LL long long

using namespace std;

const LL kInf = 1e18;
LL n, ans = kInf, a[801], b[801], f[801][801];

int main() {
  freopen("scalar.in", "r", stdin);
  freopen("scalar.out", "w", stdout);
  cin >> n;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (LL i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
  fill(&f[0][0], &f[800][800] + 1, kInf), f[1][1] = 0;
  for (LL i = 1; i <= n; i++) {
    for (LL j = 1; j <= i; j++) {
      LL k = n - i + j;
      f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + a[i] * b[j]);
      f[i + 1][j] = min(f[i + 1][j], f[i][j] + a[i] * b[k]);
    }
  }
  for (LL i = 1; i <= n; i++) {
    ans = min(ans, f[n + 1][i]);
  }
  cout << ans;
  return 0;
}
/*
cd "e:\DengYufan\scalar\" ; if ($?) { g++ -std=c++14 "sample.cpp" -o "sample.exe" } ; if ($?) { .\sample.exe }
cd "e:\DengYufan\scalar\" ; if ($?) { g++ -std=c++14 "scalar.cpp" -o "scalar.exe" } ; if ($?) { .\scalar.exe }
cd "e:\DengYufan\scalar\" ; if ($?) { g++ -std=c++14 "test.cpp" -o "test.exe" } ; if ($?) { .\test.exe }
*/
