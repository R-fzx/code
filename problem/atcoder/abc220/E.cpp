#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e6 + 1;
const LL kM = 998244353;

int n, d;
LL p2[kN] = {1}, ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 1; i < kN; ++i) {
    p2[i] = p2[i - 1] * 2 % kM;
  }
  cin >> n >> d;
  for (int i = 0; i <= d; ++i) {
    int j = d - i, k = max(i, j);
    // (p2[n - k] - 1 + kM) % kM;
    // i ? p2[i - 1] : 1;
    // j ? p2[j - 1] : 1;
    if (n > k) {
      ans = (ans + (p2[n - k] - 1 + kM) % kM * (i ? p2[i - 1] : 1) % kM * (j ? p2[j - 1] : 1) % kM) % kM;
    }
  }
  cout << ans * 2 % kM;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}