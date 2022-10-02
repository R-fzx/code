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

LL a, b, x, y;

bool Exgcd(LL a, LL b, LL &x, LL &y) {
  if (!b) {
    return x = a, a == 1;
  }
  bool f = Exgcd(b, a % b, y, x);
  return y -= a / b * x, f;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  Exgcd(a, b, x, y);
  cout << (x + b) % b;
  return 0;
}
/*
ax+by=1
by'+(a%b)x'=1
by'+(a-a/b*b)x'=1
by'+ax'-(a/b*x')b=1
ax'+b(y'-a/b*x')=1
*/