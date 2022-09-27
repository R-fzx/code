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

int t, n, a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> a >> b;
    if (a == b) {
      cout << "-1\n";
      continue;
    }
    if (a < b) {
      if (n - b + 1 > n / 2 || a - 1 + 1 > n / 2) {
        cout << "-1\n";
        continue;
      }
      int k = a;
      for (int i = n; i > b; --i) {
        cout << i << ' ';
      }
      cout << a << ' ';
      for (int c = n - b + 2; c <= n / 2; ++c) {
        cout << ++k << ' ';
      }
      for (int i = 1; i < a; ++i) {
        cout << i << ' ';
      }
      cout << b << ' ';
      for (; ++k < b;) {
        cout << k << ' ';
      }
      cout << '\n';
    } else {
      if (a == n / 2 + 1 && b == n / 2) {
        for (int i = n; i >= 1; --i) {
          cout << i << ' ';
        }
        cout << '\n';
      } else {
        cout << "-1\n";
      }
    }
  }
  return 0;
}