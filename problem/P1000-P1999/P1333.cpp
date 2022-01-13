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

const int kN = 1001;

map<string, int> t;
int n, m, c[kN], f[kN];
Pll e[kN * kN];
string a, b;

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while (cin >> a >> b) {
    int &x = t[a], &y = t[b];
    !x && (x = ++n), !y && (y = ++n), ++c[x], ++c[y], e[++m] = {x, y};
  }
  iota(f + 1, f + n + 1, 1), for_each(e + 1, e + m + 1, [](Pll x) { x.first = F(x.first), x.second = F(x.second), x.first != x.second && (f[x.first] = x.second); }), for_each(f + 1, f + n + 1, [](int &x) { x = F(x); });
  // for (int i = 1; i <= n; ++i) {
  //   cout << f[i] << " ";
  // }
  // cout << endl;
  cout << (count_if(c + 1, c + n + 1, [](int x) { return x & 1; }) > 2 || (sort(f + 1, f + n + 1), unique(f + 1, f + n + 1) - f - 1) > 1 ? "Impossible" : "Possible");
  // for (int i = 1; i <= n; ++i) {
  //   cout << c[i] << " ";
  // }
  // cout << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}