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
#include <queue>
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

int t, n, s[kN], ans[2];
Pii a[kN];
priority_queue<int> q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    fill_n(a + 1, n, Pii{0, 0});
    for (int i = 1, x, y; i <= n; ++i) {
      cin >> x >> y;
      ++a[x].first, a[x].second += y, s[i] = 0;
    }
    ans[0] = ans[1] = 0;
    sort(a + 1, a + n + 1, greater<Pii>());
    s[0] = a[1].first + 1;
    for (int i = 1; i <= n && s[i - 1] && a[i].first; ++i) {
      debug("%d %d\n", a[i].first, a[i].second);
      ans[0] += (s[i] = min(s[i - 1] - 1, a[i].first));
    }
    debug("\n");
    q = priority_queue<int>();
    for (int i = 1, j = 1; i <= n && s[i]; ++i) {
      for (; j <= n && a[j].first >= s[i]; ++j) {
        q.push(a[j].second);
      }
      ans[1] += min(q.top(), s[i]), q.pop();
    }
    cout << ans[0] << " " << ans[1] << endl;
  }
  return 0;
}