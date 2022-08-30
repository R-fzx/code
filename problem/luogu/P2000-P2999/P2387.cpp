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
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 5e4 + 1;

struct LCT {
  struct E {
    int s, v, f, c[2];
    bool r;
  } e[kN];

  int W(int x) { return e[e[x].f].c[1] == x; }
  bool nR(int x) { return e[e[x].f].c[W(x)] == x; }
  void Pu(int x) {
    
  }
  void Pr(int x) { e[x].r ^= 1, swap(e[x].c[0], e[x].c[1]); }
  
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  return 0;
}