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

const int kN = 5e4 + 1;

struct E {
  LL c[6][4]; // 长度为 i，以 j 结尾的不降子序列个数
  int t;
} e[kN << 2];
int n, q;

int main() {
  RF("sendpoints");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  return 0;
}