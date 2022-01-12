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

enum Color {
  kR,
  kB
};
struct RBT_Node {
  int v, l[2], f;
  Color c;
} e[kN];
int rt;
int Where(int x) { return x == e[e[x].f].l[1]; }
void Connect(int x, int y, int d) { y && (e[y].f = x), (x ? e[x].l[d] : rt) = y; }
void Rotate(int x, int d /* 0 left  1 right */) {
  int y = e[x].l[d ^ 1];
  Connect(x, e[y].l[d], d ^ 1), Connect(e[x].f, y, Where(x)), Connect(y, x, d);
}
void _Insert(int x, RBT_Node v) {

}
void Insert()

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}