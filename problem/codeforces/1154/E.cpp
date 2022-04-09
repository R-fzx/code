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
#include <iomanip>
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

int n, k, a[kN], pr[kN], b[kN], p[kN], ne[kN];
bool v[kN];

int Fp(int x) {
  if (x < 1 || x > n) {
    return -1;
  }
  return pr[x] == x ? x : (pr[x] = Fp(pr[x]));
}
int Fn(int x) {
  if (x < 1 || x > n) {
    return -1;
  }
  return ne[x] == x ? x : (ne[x] = Fn(ne[x]));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]] = pr[i] = ne[i] = i;
  }
  for (int _i = n, _ = 1; _i; _ = 3 - _) {
    int i = p[_i];
    debug("%d %d\n", _i, i);
    for (int j = i, c = 1; ~j && c <= k + 1; ++c) {
      debug("%d\n", j);
      v[a[j]] = 1, b[j] = _, pr[j] = j - 1, ne[j] = j + 1, j = Fp(j);
    }
    debug("\n");
    for (int j = i, c = 1; ~j && c <= k + 1; ++c) {
      debug("%d\n", j);
      v[a[j]] = 1, b[j] = _, pr[j] = j - 1, ne[j] = j + 1, j = Fn(j);
    }
    for (; v[_i]; --_i) {
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << b[i];
  }
  return 0;
}