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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;
const LL kM = 998244353;

int n;
LL a[kN], b[kN], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] *= 1LL * i * (n - i + 1);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i) {
    ans = (ans + a[i] % kM * b[n - i + 1] % kM) % kM;
  }
  cout << ans;
  return 0;
}