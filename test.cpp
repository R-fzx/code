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

int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("test.out", "w", stdout);
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j)
      cout << (((i | j) == i) ? '.' : ' ');
    cout << '\n';
  }
  return 0;
}