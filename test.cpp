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
  int a[6] = {0, 1, 2, 3, 4, 5};
  cout << lower_bound(a + 1, a + 6, 5) - a;
  return 0;
}