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

string s;
int c[26];

bool P(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return 0;
    }
  }
  return x > 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s;
  for (char i : s) {
    ++c[i - 'a'];
  }
  int mx = 0, mn = s.size();
  for (int i = 0; i < 26; ++i) {
    if (c[i]) {
      mx = max(mx, c[i]), mn = min(mn, c[i]);
    }
  }
  if (P(mx - mn)) {
    cout << "Lucky Word\n" << mx - mn;
  } else {
    cout << "No Answer\n0";
  }
  return 0;
}