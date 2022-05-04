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

int n;
vector<int> e[kN];
Pii a[kN];

int D(int x, int f, int l) {
  int r = l - 1;
  for (int i : e[x]) {
    if (i ^ f) {
      r = D(i, x, r + 1);
    }
  }
  a[x] = {l, max(l, r)};
  return max(l, r);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1, 0, 1);
  for (int i = 1; i <= n; ++i) {
    cout << a[i].first << " " << a[i].second << endl;
  }
  return 0;
}
/*

*/