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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int c = 0;
  for (int i = 0; i <= 8; ++i) {
    for (int j = 0; j <= 8; ++j) {
      if ((j - 4) * (j - 4) + (i - 4) * (i - 4) <= 4 * 4) {
        cout << i << " " << j << endl;
        ++c;
      }
    }
  }
  cout << c;
  return 0;
}
/*
(i,j) to (4,4)
(j-4)*(j-4)+(i-4)*(i-4)<=4*4
*/