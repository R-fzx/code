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

const int kN = 2e5 + 2;

int n, k, p[kN];
LL f[kN];
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> s;
  p[n + 1] = 1e9;
  for (int i = n; i; --i) {
    p[i] = (s[i - 1] == '1' ? i : p[i + 1]);
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] + i;
    int j = p[max(i - k, 1)];
    if (j <= i + k) {
      f[i] = min(f[i], f[max(j - k, 1) - 1] + j); 
    }
  }
  cout << f[n];
  return 0;
}