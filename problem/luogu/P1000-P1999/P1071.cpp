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

string a, b, s;
char f[26], p[26];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b >> s;
  for (int i = 0; i < a.size(); ++i) {
    if (f[a[i] - 'A'] && f[a[i] - 'A'] != b[i]) {
      cout << "Failed";
      return 0;
    }
    if (p[b[i] - 'A'] && p[b[i] - 'A'] != a[i]) {
      cout << "Failed";
      return 0;
    }
    f[a[i] - 'A'] = b[i], p[b[i] - 'A'] = a[i];
  }
  if (count_if(f, f + 26, [](char i) { return i; }) < 26) {
    cout << "Failed";
    return 0;
  }
  for (char i : s) {
    cout << f[i - 'A'];
  }
  return 0;
}