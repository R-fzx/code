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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e6 + 1;

int t, n;
LL f[kN], s[kN];

LL S(LL x) {
  LL s = 0;
  for (; x; x /= 10) {
    s += x % 10;
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  f[1] = s[1] = 1;
  for (int i = 2; i < kN; ++i) {
    f[i] = S(f[i - 1] + f[i - 2]), s[i] = (s[i - 1] + f[i]) % 9;
  }
  cin >> t;
  while (t--) {
    cin >> n;
    cout << s[n] << "\n";
  }
  return 0;
}