#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pdd = pair<double, double>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 1e5 + 1;

int n, l[kN], t, ad;
double ans;
Pdd a[kN];

const Pdd operator-(const Pdd &x, const Pdd &y) {
  return {x.first - y.first, x.second - y.second};
}
LL Cross(Pdd o, Pdd x, Pdd y) {
  x = x - o, y = y - o;
  return x.first * y.second - x.second * y.first;
}
double D(Pdd x, Pdd y) {
  return hypot((x - y).first, (x - y).second);
}

int main() {
  // freopen("P1452_1.in", "r", stdin);
  // freopen("P1452.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    for (; t > 1 && Cross(a[l[t - 1]], a[l[t]], a[i]) <= 0; --t) {
    }
    l[++t] = i;
  }
  for (int i = n - 1, j = t; i >= 1; --i) {
    for (; t > j && Cross(a[l[t - 1]], a[l[t]], a[i]) <= 0; --t) {
    }
    l[++t] = i;
  }
  --t;
  for (int i = 1, j = 2; i <= t; ++i) {
    cout << a[l[i]].first << " " << a[l[i]].second << endl;
    for (; Cross(a[l[j % t + 1]], a[l[i]], a[l[i % t + 1]]) > Cross(a[l[j]], a[l[i]], a[l[i % t + 1]]); j = j % t + 1) {
    }
    ans = max(ans, max(D(a[l[i]], a[l[j]]), D(a[l[i % t + 1]], a[l[j]])));
  }
  printf("%.10lf", ans / 2);
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}