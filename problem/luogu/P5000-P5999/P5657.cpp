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
using uLL = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int n;
uLL k;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = n - 1; i >= 0; --i) {
    if (k >> i & 1) {
      cout << 1, k ^= (1uLL << i) - 1;
    } else {
      cout << 0;
    }
  }
  return 0;
}