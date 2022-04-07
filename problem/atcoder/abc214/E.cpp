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
#include <set>
#include <string>
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

const int kN = 2e5 + 1;

int t, n;
unordered_map<int, int> p;
Pii a[kN];

int F(int x) { return !p[x] ? x : (p[x] = F(p[x])); }
bool C() {
  for (int i = 1; i <= n; ++i) {
    int x = F(a[i].first);
    if (x > a[i].second) {
      return 0;
    }
    p[x] = x + 1;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    p.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, [](Pii x, Pii y) { return x.second < y.second; });
    cout << (C() ? "Yes" : "No") << endl;
  }
  return 0;
}