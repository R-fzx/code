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

const int kN = 11;

int n;
LL x, a[kN], ans;

int main() {
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = n; i; --i) {
    LL v = x % a[i];
    if (v <= a[i] - v || (v - a[i] + v) < a[i - 1]) {
      ans += x / a[i], x = v;
    } else {
      ans += x / a[i] + 1, x = a[i] - v;
    }
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
87

*/