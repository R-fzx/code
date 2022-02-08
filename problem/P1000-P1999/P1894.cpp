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
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 201;

int n, m, p[kN], v[kN], t, s;
vector<int> ne[kN];

bool F(int x) {
  if (v[x] ^ t) {
    v[x] = t;
    for (int i : ne[x]) {
      if (!p[i] || F(p[i])) {
        return p[i] = x;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, j; i <= n; ++i) {
    cin >> j;
    for (int k = 1, x; k <= j; ++k) {
      cin >> x;
      ne[i].push_back(x);
    }
  }
  for (t = 1; t <= n; ++t) {
    s += F(t);
  }
  cout << s;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}