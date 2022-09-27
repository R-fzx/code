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

LL n, m, l, p;

LL M(LL x, LL y) {
  LL s = 0;
  for (; y; y >>= 1, x = x * 2 % p) {
    (y & 1) && (s = (s + x) % p);
  }
  return s;
}
LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = M(b, b)) {
    (e & 1) && (s = M(s, b));
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> l, p = n + 1;
  cout << M(l, P(n / 2 + 1, m));
  return 0;
}
/*
x->2x mod n+1
x*2^m===l (mod n+1)
x===l*(n/2+1)^m (mod n+1)
*/