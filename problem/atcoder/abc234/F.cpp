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

const LL kM = 998244353;
const int kN = 5001, kC = 27;

string s;
int n, c[kC];
LL ans, fc[kN] = {1}, ifc[kN] = {1}, f[kC][kN];

LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    if (e & 1) {
      s = s * b % kM;
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 1; i < kN; ++i) {
    ifc[i] = P(fc[i] = fc[i - 1] * i % kM, kM - 2);
  }
  cin >> s;
  n = s.size();
  for (char i : s) {
    ++c[i - 'a' + 1];
  }
  f[0][0] = 1;
  for (int i = 1; i < kC; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= min(c[i], j); ++k) {
        f[i][j] = (f[i][j] + f[i - 1][j - k] * fc[j] % kM * ifc[j - k] % kM * ifc[k] % kM) % kM;
      }
      // cout << f[i][j] << " ";
    }
    // cout << endl;
  }
  for (int i = 1; i <= n; ++i) {
    ans = (ans + f[kC - 1][i]) % kM;
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
j-k+1 -> m
k -> n
C(n+m-1, m-1)
C(k+j-k+1-1, j-k)
C(j, j-k)
j!/(j-k)!/k!
*/