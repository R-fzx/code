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
#include <random>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

random_device rd;
mt19937 rnd(rd());

vector<Pii> e;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n = uniform_int_distribution<int>(1, 1000)(rnd), m = uniform_int_distribution<int>(0, n - 1)(rnd);
  cout << n << " " << m << endl;
  for (int i = 2; i <= n; ++i) {
    e.emplace_back(i, uniform_int_distribution<int>(1, i - 1)(rnd));
  }
  shuffle(e.begin(), e.end(), rnd);
  for (int i = 0; i < m; ++i) {
    cout << e[i].first << " " << e[i].second << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}