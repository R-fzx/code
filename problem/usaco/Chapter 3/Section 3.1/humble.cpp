/*
ID: wsfxk.e1
LANG: C++
TASK: humble
*/
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
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define RF(s)
#else
#define debug(...)
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kK = 101;

int n, k, a[kK], x;
priority_queue<int, vector<int>, greater<int>> q;
bitset<1uLL << 31> v;

int main() {
  RF("humble");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> k >> n;
  for (int i = 1; i <= k; ++i) {
    cin >> a[i];
  }
  for (q.push(1); x = q.top(), n--;) {
    // debug("%d\n", x);
    q.pop();
    for (int i = 1; i <= k; ++i) {
      LL y = (LL)x * a[i];
      if (y <= INT32_MAX && !v[y]) {
        v[y] = 1, q.push(y);
      }
    }
  }
  cout << x << '\n';
  return 0;
}