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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

__int128_t G(__int128_t x, __int128_t y) {
  return y ? G(y, x % y) : x;
}
void W(__int128_t x) {
  putchar(x + '0');
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  // W(G(78569350599398894027251472817058687522, 127127879743834334146972278486287885163));
  numeric_limits<int>::max();
  return 0;
}