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

const int kN = 5e5 + 1;

int n, q, a[kN], b[kN], p[kN], l[kN], t, ans[kN], d[kN], s[kN];
Pii e[kN];
vector<int> _p[kN];

void A(int x) {
  for (; x <= n; x += x & -x) {
    ++s[x];
  }
}
int S(int x) {
  int _s = 0;
  for (; x; x -= x & -x) {
    _s += s[x];
  }
  return _s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  for (int i = n; i >= 1; --i) {
    for (; t && a[l[t]] != a[i] && b[l[t]] < b[i]; p[l[t]] = i + 1, --t) {
    }
    l[++t] = i;
  }
  for (int i = 1; i <= n; ++i) {
    // cerr << p[i] << " ";
    _p[p[i]].push_back(i);
  }
  // for (int i = 0; i <= n; ++i) {
  //   for (int j : _p[i]) {
  //     cerr << j << " ";
  //   }
  //   cerr << endl;
  // }
  for (int i = 1; i <= q; ++i) {
    cin >> e[i].first >> e[i].second;
    d[i] = i;
  }
  sort(d + 1, d + q + 1, [](int i, int j) { return e[i] < e[j]; });
  e[0].first = -1;
  for (int i = 1; i <= q; ++i) {
    // cerr << d[i] << endl;
    for (int j = e[d[i - 1]].first + 1; j <= e[d[i]].first; ++j) {
      for (int k : _p[j]) {
        A(k);
      }
    }
    ans[d[i]] = S(e[d[i]].second) - S(e[d[i]].first - 1);
  }
  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}