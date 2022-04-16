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

const int kN = 12;

LL l, r, f[kN][10];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fill(&f[0][0], &f[kN - 1][9] + 1, -1);
  cin >> l >> r;
  
  return 0;
}
/*
len=3
p=[0,3,2,1]
now=[0,3,23,123]
*/