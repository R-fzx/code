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

const int kN = 1e5 + 2, kM = 301;

int n, m, a[kN], d[kN];
Pii b[kM];
vector<int> l;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    d[i] = a[i] - a[i - 1];
  }
  d[n + 1] = -a[n];
  int _m = max_element(a + 1, a + n + 1) - a;
  for (int i = 1; i <= m; ++i) {
    cin >> b[i].first >> b[i].second;
    if (b[i].first > _m || b[i].second < _m) {
      l.push_back(i);
      --d[b[i].first], ++d[b[i].second + 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i - 1] + d[i];
  }
  cout << *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1) << '\n';
  cout << l.size() << endl;
  for (int i : l) {
    cout << i << ' ';
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}