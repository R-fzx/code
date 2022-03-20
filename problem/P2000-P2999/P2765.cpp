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

const int kN = 56;

int n, c;
vector<int> a[kN];
bitset<kN * kN> b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 1; i < kN; ++i) {
    b[i * i] = 1;
  }
  cin >> n;
  int ans = (n * n - 1 - (n & 1 ^ 1)) / 2 + n;
  cout << ans << endl;
  for (int i = 1; i <= ans; ++i) {
    bool f = 0;
    for (int j = 1; j <= c; ++j) {
      if (b[a[j].back() + i]) {
        a[j].push_back(i), f = 1;
        break;
      }
    }
    if (!f) {
      a[++c].push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j : a[i]) {
      cout << j << " ";
    }
    cout << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}