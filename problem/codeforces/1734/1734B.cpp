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

int t, n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n;
    cout << "1\n";
    for (int i = 2; i <= n; ++i) {
      cout << "1 ";
      for (int j = 1; j < i - 1; ++j) {
        cout << "0 ";
      }
      cout << "1\n";
    }
  }
  return 0;
}
/*
             1
            1 1
           1 0 1
          1 0 0 1
         1 0 0 0 1
        1 0 0
*/