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

const int kN = 1001;

int n, m;
unordered_map<int, int> mp;

bool C() {
  for (int i = 1, x, p = 0; i <= m; p = x, ++i) {
    cin >> x;
    if (/*p == x || */!mp[x]) {
      return 0;
    }
    --mp[x];
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    ++mp[x];
  }
  cout << (C() ? "Yes" : "No");
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}