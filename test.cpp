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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, a[10000], b[10000];
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  int m = unique(b + 1, b + n + 1) - b;
  for (int i = 1; i <= n; ++i) {
    cout << lower_bound(b + 1, b + m, a[i]) - b << " ";
  }
  return 0;
}