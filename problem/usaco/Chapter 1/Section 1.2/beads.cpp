/*
ID: wsfxk.e1
LANG: C++
TASK: beads
*/
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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 351;

int n, a[kN], ans;

int G(int s, int d, int l, int c) {
  int i = s;
  for (; i >= 1 && i <= n && i != l && (a[i] == c || a[i] == 2); i += d) {
  }
  return i;
}
int C(int s, int d, int l) {
  return a[s] == 2 ? max(G(s, d, l, 0), G(s, d, l, 1)) : G(s, d, l, a[s]);
}

int main() {
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    char ch;
    cin >> ch;
    a[i] = (ch == 'w' ? 2 : ch == 'b');
  }
  for (int _ = 1; _ <= n; ++_) {
    int x = C(1, 1, -1) - 1;
    ans = max(ans, x + n - C(n, -1, x)), rotate(a + 1, a + 2, a + n + 1);
  }
  cout << ans << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}