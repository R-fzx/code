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

const int kN = 1e5 + 1;

Mll lg;
void Init(int n) {
  for (LL i = 0, s = 1; s <= n; lg[s] = i++, s <<= 1) {
  }
}
struct vEB {
  int u, p, mi, mx, su;
  vector<int> l;
} e[kN];
int Where(int o, int x) { return x / e[o].su; }
int Pos(int o, int x) { return x % e[o].su; }
int Index(int o, int w, int p) { return w * e[o].su + p; }
bool Contains(int o, int x) { return x == e[o].mi || x == e[o].mx || (e[o].u > 2 && Contains(e[o].l[Where(o, x)], Pos(o, x))); }
int Min(int o) { return e[o].mi; }
int Max(int o) { return e[o].mx; }


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}