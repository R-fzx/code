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
#include <set>
#include <vector>
#include <cstring>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e6 + 1, kC = 20, kM = 1 << kC;

char a[kN];
int n, f[kM], ans;
bool v[kM];

int C(int x) {
  int c = 0;
  for (; x; c += x & 1, x >>= 1) {
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  scanf("%s", a + 1), n = strlen(a + 1);
  for (int i = 1; i <= n; ++i) {
    int j = i;
    for (int _v = 0; j && (_v >> a[j] - 'a' & 1 ^ 1); --j) {
      _v |= 1 << a[j] - 'a', v[_v] = 1;
    }
    ans = max(ans, i - j);
  }
  for (int i = 1; i < kM; ++i) {
    f[i] = v[i] ? C(i) : -1;
    for (int j = 0; j < kC; ++j) {
      f[i] = max(f[i], f[i ^ (1 << j)]);
    }
    ans = max(ans, v[kM - 1 ^ i] ? C(kM - 1 ^ i) + f[i] : -1);
  }
  cout << ans;
  return 0;
}