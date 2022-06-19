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

const int kN = 20, kL = 1 << kN, kM = 101;

int n, m, t[kM], b[kM][2], f[kM][2];
LL d[kL];
vector<Pii> e[kL];
priority_queue<Pii, vector<Pii>, greater<Pii>> q;

void R(int x, LL _d) {
  if (d[x] > _d) {
    d[x] = _d, q.push({_d, x});
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    char c;
    cin >> t[i];
    for (int j = 0; j < n; ++j) {
      cin >> c;
      if (c != '0') {
        b[i][c == '-'] |= 1 << j;
      }
    }
    for (int j = 0; j < n; ++j) {
      cin >> c;
      if (c != '0') {
        f[i][c == '+'] |= 1 << j;
      }
    }
  }
  fill_n(d, 1 << n, 1e18);
  for (R((1 << n) - 1, 0); !q.empty();) {
    int x = q.top().second;
    q.pop();
    for (int i = 1; i <= m; ++i) {
      if ((x | b[i][0]) == x && !(x & b[i][1])) {
        R(x & ~f[i][0] | f[i][1], d[x] + t[i]);
      }
    }
  }
  cout << (d[0] == 1e18 ? 0 : d[0]);
  return 0;
}