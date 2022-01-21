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

struct E {
  int v, c, s, l[2];
} e[kN];
int q, o, x, rt, c;

void PushUp(int x) { e[x].s = e[e[x].l[0]].s + e[e[x].l[1]].s + e[x].c; }
int &Max(int x) { return e[x].l[1] ? Max(e[x].l[1]) : x; }
int &Min(int x) { return e[x].l[0] ? Min(e[x].l[0]) : x; }
int Pre(int x, int v) { return x ? (e[x].v < v ? max(e[x].v, Pre(e[x].l[1], v)) : Pre(e[x].l[0], v)) : INT32_MIN; }
int Next(int x, int v) { return x ? (e[x].v > v ? min(e[x].v, Next(e[x].l[0], v)) : Next(e[x].l[1], v)) : INT32_MAX; }
int At(int x, int r) {
  if (!x) {
    return -1;
  }
  int s = e[e[x].l[0]].s;
  if (r <= s) {
    return At(e[x].l[0], r);
  } else if (r <= s + e[x].c) {
    return e[x].v;
  } else {
    return At(e[x].l[1], r - s - e[x].c);
  }
}
int Rank(int x, int v) {
  if (!x) {
    return 0;
  }
  int s = e[e[x].l[0]].s;
  if (e[x].v < v) {
    return Rank(e[x].l[1], v) + s + e[x].c;
  } else if (e[x].v == v) {
    return s;
  } else {
    return Rank(e[x].l[0], v);
  }
}
void Insert(int &x, int v) {
  if (!x) {
    e[x = ++c] = {v, 1, 1};
    return;
  }
  e[x].v == v ? ++e[x].c : (Insert(e[x].l[e[x].v < v], v), 0), PushUp(x);
}
void Delete(int &x, int v) {
  if (e[x].v == v) {
    if (!--e[x].c) {
      if (!e[x].l[0] && !e[x].l[1]) {
        x = 0;
      } else if (!e[x].l[0] || !e[x].l[1]) {
        x = e[x].l[!e[x].l[0]];
      } else {
        int &m = Max(e[x].l[0]);
        e[x].v = e[m].v, e[x].c = e[m].c, m = e[m].l[0];
      }
    }
  } else {
    Delete(e[x].l[e[x].v < v], v);
  }
  PushUp(x);
}

int main() {
  // freopen("BST.in", "r", stdin);
  // freopen("BST.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> o >> x;
    if (o == 1) {
      Insert(rt, x);
    } else if (o == 2) {
      Delete(rt, x);
    } else if (o == 3) {
      cout << Rank(rt, x) + 1 << endl;
    } else if (o == 4) {
      cout << At(rt, x) << endl;
    } else if (o == 5) {
      cout << Pre(rt, x) << endl;
    } else {
      cout << Next(rt, x) << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}