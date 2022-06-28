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

const int kN = 2e5 + 1;

int n, a[2][kN], b[2][kN], ca[2], cb[2], c;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      ++ca[a[i][j]];
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> b[i][j];
      ++cb[b[i][j]];
      c += b[i][j] && !a[i][j];
    }
  }
  cout << (ca[0] == cb[0] ? c : -1);
  return 0;
}