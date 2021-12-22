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
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 2e5 + 1;

int n, ans, c[kN], f[kN];
vector<int> e[kN];

void D(int x, int _f) {
  for (int i : e[x]) {
    if (i != _f) {
      D(i, x), c[x] += !c[i];
    }
  }
}
void S(int x, int _f) {
  ans += !f[x];
  for (int i : e[x]) {
    if (i != _f) {
      f[i] = c[i] + !(f[x] - !c[i]);
      S(i, x);
    }
  }
}

int main() {
  // freopen("G.in", "r", stdin);
  // freopen("G.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  f[0] = 1, D(1, 0), f[1] = c[1], S(1, 0);
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}