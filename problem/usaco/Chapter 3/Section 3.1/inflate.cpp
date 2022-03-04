/*
ID: wsfxk.e1
LANG: C++
TASK: inflate
*/
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
using ULL = unsigned long long;
using Pii = pair<int, int>;

const int kN = 10001;

int n, m, f[kN];
Pii a[kN];

int main() {
  freopen("inflate.in", "r", stdin);
  freopen("inflate.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = a[i].second; j <= m; ++j) {
      f[j] = max(f[j], f[j - a[i].second] + a[i].first);
    }
  }
  cout << f[m] << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}