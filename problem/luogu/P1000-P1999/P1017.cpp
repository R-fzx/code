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

const int kK = 50;

int n, r, st[kK], t;

char C(int x) { return x < 10 ? x + '0' : x - 10 + 'A'; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> r;
  cout << n << '=';
  for (; n; n /= r) {
    if (n % r < 0) {
      st[++t] = n % r - r, n += r;
    } else {
      st[++t] = n % r;
    }
  }
  for (; t; cout << C(st[t--])) {
  }
  cout << "(base" << r << ")";
  return 0;
}
/*
6 0
3 1
1 1
*/