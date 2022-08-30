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

Pii a[4];

int C(Pii o, Pii a, Pii b) { return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 0; i < 4; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < 4; ++i) {
    if (C(a[(i + 3) % 4], a[i], a[(i + 1) % 4]) < 0) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}