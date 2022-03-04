#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 5001;
const LL kM = 998244353;

int n, m;
LL f[kN][kN], s[kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  f[0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    s[i][0] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= j / i; ++k) {
        f[i][j] = (f[i][j] + s[i - 1][j - k * i] - (i <= m ? 0 : s[i - m - 1][j - k * i]) + kM) % kM;
        // for (int p = max(0, i - m); p < i; ++p) {
        //   f[i][j] = (f[i][j] + f[p][j - k * i]) % kM;
        // }
      }
      s[i][j] = (s[i - 1][j] + f[i][j]) % kM;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << f[i][n] << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}