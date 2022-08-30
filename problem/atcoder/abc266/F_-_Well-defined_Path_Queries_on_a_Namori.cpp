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

const int kN = 2e5 + 1;

int n, c[kN], q;
vector<int> e[kN], l;
bool v[kN];

int D(int x, int f) {
  if (v[x]) {
    return x;
  }
  v[x] = 1;
  for (int i : e[x]) {
    int y;
    if (i != f && (y = D(i, x))) {
      l.push_back(x);
      if (x == y) {
        return 0;
      } else {
        return y;
      }
    }
  }
  v[x] = 0;
  return 0;
}
void F(int x, int f, int _c) {
  if (v[x]) {
    return;
  }
  c[x] = _c;
  for (int i : e[x]) {
    if (i != f) {
      F(i, x, _c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1, 0);
  // for (int i = 1; i <= n; ++i) {
  //   cout << v[i] << ' ';
  // }
  for (int i = 0; i < l.size(); ++i) {
    v[l[i]] = 0, F(l[i], 0, i), v[l[i]] = 1;
  }
  cin >> q;
  for (int x, y; q--; ) {
    cin >> x >> y;
    cout << (c[x] == c[y] ? "Yes" : "No") << '\n';
  }
  return 0;
}