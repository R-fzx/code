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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n = rnd() % 3 + 1;
  for (int i = 1; i <= n; ++i) {
    cout << char(rnd() % 26 + 'a');
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}