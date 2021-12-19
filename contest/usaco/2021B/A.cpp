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
// #define TIME

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pdd = pair<double, double>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 5e5 + 2;

int n;
LL c, a[kN], b[kN];
string s;
Mll p[2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  s = "#" + s;
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i - 1] + (s[i] == 'G'), b[i] = i - a[i];
  }
  for (int i = 3; i <= n; ++i) {
    ++p[0][a[i - 3] + 1], ++p[1][b[i - 3] + 1];
    c += p[0][a[i]] + p[1][b[i]];
  }
  cout << c;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
i j
a[j] == a[i - 1] + 1
b[j] == b[i - 1] + 1
5
GHGHG
11223
01122
p[0]
00100
p[1]
01000
*/