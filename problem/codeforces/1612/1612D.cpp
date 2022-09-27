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

int t;
LL a, b, x;

bool G(LL a, LL b) {
  if (x == a || x == b) {
    return 1;
  }
  if (x > a && x > b) {
    return 0;
  }
  if (a < b) {
    swap(a, b);
  }
  return (a - x) % b == 0 ? 1 : G(a % b, b);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> a >> b >> x;
    cout << (G(a, b) ? "YES" : "NO") << '\n';
  }
  return 0;
}