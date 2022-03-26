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

const int kD[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

int n, x, y, d;
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  for (char c : s) {
    if (c == 'S') {
      x += kD[d][0], y += kD[d][1];
    } else {
      d = (d + 1) % 4;
    }
  }
  cout << x << " " << y;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}