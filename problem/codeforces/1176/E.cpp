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

int t, n, m;
vector<int> e[kN];
bool v[kN];
vector<int> l[2];

void D(int x, int d) {
  if (v[x]) {
    return;
  }
  v[x] = 1, l[d].push_back(x);
  for (int i : e[x]) {
    D(i, d ^ 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
    }
    for (int i = 1, x, y; i <= m; ++i) {
      cin >> x >> y;
      e[x].push_back(y), e[y].push_back(x);
    }
    fill_n(v + 1, n, 0);
    l[0].clear(), l[1].clear();
    D(1, 0);
    int d = l[0].size() > n / 2;
    cout << l[d].size() << endl;
    for (int i : l[d]) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}