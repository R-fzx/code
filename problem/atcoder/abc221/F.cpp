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
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;
const LL kM = 998244353;

int n, d[kN] = {-1}, p[kN];
vector<int> e[kN];

void D(int x, int f = 0) {
  d[x] = d[f] + 1, p[x] = f;
  for (int i : e[x]) {
    if (i ^ f) {
      D(i, x);
    }
  }
}
LL F(int x, int f, int _d, int v) {
  int c = _d == v;
  for (int i : e[x]) {
    if (i ^ f) {
      c += F(i, x, _d + 1, v);
    }
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1);
  int x = max_element(d + 1, d + n + 1) - d;
  D(x);
  int y = max_element(d + 1, d + n + 1) - d, l = d[y];
  // cerr << x << " " << y << " " << d[y] << endl;
  if (l & 1) {
    int m[2] = {y, y};
    for (int i = l / 2; i--; m[0] = p[m[0]]) {
    }
    m[1] = p[m[0]];
    // cerr << m[0] << " " << m[1] << endl;
    cout << F(m[0], m[1], 0, l / 2) * F(m[1], m[0], 0, l / 2) % kM;
  } else {
    int m = y;
    for (int i = l / 2; i--; m = p[m]) {
    }
    // cerr << m << endl;
    LL ans = 1, c = 0;
    for (int i : e[m]) {
      int j = F(i, m, 1, l / 2);
      ans = ans * (j + 1) % kM, c += j;
    }
    cout << (ans - c - 1 + kM) % kM;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}