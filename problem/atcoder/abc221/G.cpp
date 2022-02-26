#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2001, kD = 1801;
const string kS = "LUDR";

int n, a, b, d[kN], s, p[kN];
bitset<kN * kD> f[kN];

bool C() {
  s = accumulate(d + 1, d + n + 1, 0);
  if ((s + a & 1) || (s + b & 1) || (s + a) / 2 > s || (s + b) / 2 > s || s + a < 0 || s + b < 0) {
    return 0;
  }
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] | (f[i - 1] << d[i]);
    // for (int j = 0; j <= s; ++j) {
    //   f[i][j] = f[i - 1][j] || j >= d[i] && f[i - 1][j - d[i]];
    // }
  }
  return f[n][(s + a) / 2] && f[n][(s + b) / 2];
}
void S(int o, int x) {
  for (int i = n; i >= 1; --i) {
    if (x >= d[i] && f[i - 1][x - d[i]]) {
      x -= d[i], p[i] |= 1 << o;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> a >> b;
  a += b, b = a - b - b;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
  }
  if (C()) {
    cout << "Yes" << endl;
    S(0, (s + a) / 2), S(1, (s + b) / 2);
    for (int i = 1; i <= n; ++i) {
      cout << kS[p[i]];
    }
  } else {
    cout << "No";
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
f[i][j]->(\sum_{k=1}^{i} p_i*d_i)=j

(-1, 0)->(-1,-1)->L->(0,0)->0
( 0,-1)->(-1, 1)->D->(0,1)->1
( 0, 1)->( 1,-1)->U->(1,0)->2
( 1, 0)->( 1, 1)->R->(1,1)->3
*/