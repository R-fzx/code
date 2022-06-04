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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 151;

int n, m, p[kN], v[kN], t, s, f[kN];
vector<int> ne[kN];

bool F(int x) {
  if (v[x] ^ t) {
    v[x] = t;
    for (int i : ne[x]) {
      if (!p[i] || F(p[i])) {
        p[i] = x;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    ne[x].push_back(y);
  }
  for (t = 1; t <= n; ++t) {
    F(t);
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << p[i] << ' ';
  // }
  // cout << endl;
  for (int i = 1; i <= n; ++i) {
    if (p[i]) {
      f[p[i]] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!p[i]) {
      ++s;
      for (int j = i; j; j = f[j]) {
        cout << j << " ";
      }
      cout << endl;
    }
  }
  cout << s;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}