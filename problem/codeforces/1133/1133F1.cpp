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
#include <set>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;

int n, m, q[kN], h = 1, t;
vector<int> e[kN];
bool v[kN];
vector<Pii> ans;

void R(int x, int p) {
  if (!v[x]) {
    v[x] = 1, q[++t] = x, ans.emplace_back(x, p);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  int x = max_element(e + 1, e + n + 1, [](auto &x, auto &y) { return x.size() < y.size(); }) - e;
  // cerr << x;
  for (R(x, 0); h <= t; ++h) {
    for (int i : e[q[h]]) {
      R(i, q[h]);
    }
  }
  for (Pii i : ans) {
    if (i.second) {
      cout << i.first << " " << i.second << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}