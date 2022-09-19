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

int n, m, s, d[kN];
vector<Pii> e[kN];
bool v[kN];
deque<int> q;
random_device rd;
mt19937 rnd(rd());

void R(int x, int _d) {
  if (d[x] > _d) {
    d[x] = _d;
    if (!v[x]) {
      v[x] = 1;
      if (!q.empty() && d[x] < d[q.front()]) {
        q.push_front(x);
      } else {
        q.push_back(x);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s;
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    e[x].emplace_back(y, w);
  }
  fill(d + 1, d + n + 1, 1e9);
  for (R(s, 0); !q.empty(); ) {
    if (!uniform_int_distribution<int>(0, q.size() - 1)(rnd)) {
      sort(q.begin(), q.end(), [](int i, int j) { return d[i] < d[j]; });
    }
    int x = q.front();
    q.pop_front(), v[x] = 0;
    for (Pii i : e[x]) {
      R(i.first, d[x] + i.second);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << d[i] << ' ';
  }
  return 0;
}