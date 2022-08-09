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

const int kN = 1e5 + 1;

int n, m, d[kN][2], h[kN], s, t;
vector<int> e[kN], l;

void D(int x) {
  for (int i = h[x]; i < e[x].size(); i = h[x]) {
    ++h[x], D(e[x][i]);
  }
  l.push_back(x);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    ++d[x][0], ++d[y][1], e[x].push_back(y);
  }
  for (int i = 1; i <= n; ++i) {
    if (d[i][0] == d[i][1] + 1) {
      if (s) {
        cout << "No\n";
        return 0;
      } else {
        s = i;
      }
    } else if (d[i][0] + 1 == d[i][1]) {
      if (t) {
        cout << "No\n";
        return 0;
      } else {
        t = i;
      }
    } else if (d[i][0] != d[i][1]) {
      cout << "No\n";
      return 0;
    }
    sort(e[i].begin(), e[i].end());
  }
  D(max(s, 1));
  for (int i : vector(l.rbegin(), l.rend())) {
    cout << i << ' ';
  }
  return 0;
}