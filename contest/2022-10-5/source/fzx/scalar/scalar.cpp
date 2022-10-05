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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 801;

int n;
LL a[kN], b[kN], s;

int main() {
  RF("scalar");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i], b[i] = -b[i];
  }
  sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i) {
    s -= a[i] * b[i];
  }
  cout << s;
  return 0;
}
/*
x*(y+v)+(x+k)*y=2xy+vx+ky
x*y+(x+k)*(y+v)=2xy+vx+ky+vk
x x+k
y+v y
*/