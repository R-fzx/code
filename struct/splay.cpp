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

struct T {
  int v, s, c, l[2], f;
} e[kN];
int rt;

int Where(int x) { return x == e[e[x].f].l[1]; }
void PushUp(int x) { e[x].s = e[e[x].l[0]].s + e[e[x].l[1]].s + e[x].c; }
void Connect(int x, int y, int w) { e[x].l[w] = y, e[y].f = x; }
void Rotate(int x) {
  int y = e[x].f, z = e[y].f;
  Connect(y, e[x].l[Where(x) ^ 1], Where(x)), Connect(z, x, Where(y))
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}