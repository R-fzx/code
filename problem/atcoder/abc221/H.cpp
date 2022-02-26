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
LL f[kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int v = 1; v <= j; ++v) {
        for (int k = 1; k < i && (i - k) * v <= j; ++k) {
          f[i][j] = (f[i][j] + f[k][j - (i - k) * v]) % kM;
        }
      }
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