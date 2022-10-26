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

const int kN = 5e5 + 1;

int n, d[kN], t, f[kN];
LL ans, v[kN];
vector<int> e[kN];
string s;

void D(int x, LL fv) {
  int p = 0;
  if (s[x] == ')' && t) {
    v[x] = v[f[d[t]]] + 1, p = d[t--];
  }
  if (s[x] == '(') {
    d[++t] = x;
  }
  LL _s = fv + v[x];
  // cout << x << ' ' << _s << '\n';
  // cout << "d: ";
  // for (int i = 1; i <= t; ++i) {
  //   cout << d[i] << ' ';
  // }
  // cout << '\n';
  ans ^= x * _s;
  for (int i : e[x]) {
    D(i, _s);
  }
  if (s[x] == '(') {
    --t;
  }
  if (p) {
    d[++t] = p;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  s = " " + s;
  for (int i = 2; i <= n; ++i) {
    cin >> f[i];
    e[f[i]].push_back(i);
  }
  D(1, 0);
  cout << ans;
  return 0;
}