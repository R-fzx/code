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

const int kN = 1e5 + 1;

int t, r, o, _h, _t;
char c, a[kN];

int A(int x) {
  if (++x == kN) {
    x = 0;
  }
  return x;
}
int D(int x) {
  if (!x--) {
    x = 1e5;
  }
  return x;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &o);
    if (o == 1) {
      scanf(" %c", &c);
      if (r) {
        if (_h != _t && a[_h] == c) {
          _h = A(_h);
        } else {
          _h = D(_h), a[_h] = c;
        }
      } else {
        if (_h != _t && a[D(_t)] == c) {
          _t = D(_t);
        } else {
          a[_t] = c, _t = A(_t);
        }
      }
    } else if (o == 2) {
      r ^= 1;
    } else if (o == 3) {
      if (r) {
        for (int i = D(_t); A(i) != _h; i = D(i)) {
          putchar(a[i]);
        }
      } else {
        for (int i = _h; i != _t; i = A(i)) {
          putchar(a[i]);
        }
      }
      puts("");
    }
  }
  return 0;
}