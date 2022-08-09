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
#include <random>
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
	LL s = 0;
	for (int i = 1; i <= 1000000; ++i) {
		int x = i, c = 0;
    for (int j = 2; ++c, j * j <= x; ++j, ++c) {
      if (x % j == 0) {
        for (; ++c, x % j == 0; x /= j, ++c) {
        }
      }
    }
    s += c;
  }
  cout << s;
	return 0;
}