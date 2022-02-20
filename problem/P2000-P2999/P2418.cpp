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
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 5e5 + 1;

int n, m, a[kN], f[kN], s[3][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[1][i] = s[1][i] + (a[i] == 1), s[2][i] = s[2][i] + (a[i] == 2);
  }

#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*

*/