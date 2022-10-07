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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kV = 1e6 + 1;

int t;
bool v[kV];
vector<int> lp, lk, lb;
LL a, b, k;

int main() {
  RF("kubi");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 2; i < kV; ++i) {
    if (!v[i]) {
      lp.push_back(i);
      for (LL j = 1LL * i * i; j < kV; j += i) {
        v[j] = 1;
      }
    }
  }
  for (cin >> t; t--;) {
    cin >> a >> b >> k;
    lk.clear(), lb.clear();
    for (int i : lp) {
      if (k % i == 0) {
        lk.push_back(i);
        for (; k % i == 0; k /= i) {
        }
      }
      if (b % i == 0) {
        lb.push_back(i);
        for (; b % i == 0; b /= i) {
        }
      }
    }
    lk.push_back(k), lb.push_back(b);
  }
  return 0;
}