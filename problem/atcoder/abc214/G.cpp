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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 3001;
const LL kM = 1e9 + 7;

int n, p[kN], q[kN], pq[kN];
bool v[kN];
vector<vector<int>> l;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> q[i];
    pq[q[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (!v[i]) {
      vector<int> _l;
      _l.push_back(0);
      int j = i;
      for (; !v[j]; _l.push_back(j), v[j] = 1, j = pq[p[j]]) {
      }
      l.push_back(_l);
    }
  }
  
  return 0;
}