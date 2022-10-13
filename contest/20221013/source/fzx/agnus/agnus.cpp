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
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 3e4 + 2;

string s;
int n, m, d[kN], ans;

int main() {
  RF("agnus");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s;
  n = s.size(), s = " " + s;
  for (int i = 1; i <= n; ++i) {
    if (s.substr(i, 5) == "agnus") {
      d[++m] = i;
    }
  }
  for (int i = 1; i < m; ++i) {
    ans += d[i] * (d[i + 1] - d[i]);
  }
  cout << ans + d[m] * (n - d[m] - 3);
  return 0;
}
/*
s[x]=s[x-1]+l[x]
p[x]=p[x+1]+l[x]
l1agnusl2agnusl3agnusl4
  i1     i2     i3
+ i1*(n-i1-3)+i2*(n-i2-3)+i3*(n-i3-3)
- i1*(n-i2-3)+i2*(n-i3-3)

 2     8
pagnuspagnusp
pagnus
pagnusp
pagnuspa
pagnuspag
pagnuspagn
pagnuspagnu
pagnuspagnus
pagnuspagnusp
 agnus
 agnusp
 agnuspa
 agnuspag
 agnuspagn
 agnuspagnu
 agnuspagnus
 agnuspagnusp
  gnuspagnus
  gnuspagnusp
   nuspagnus
   nuspagnusp
    uspagnus
    uspagnusp
     spagnus
     spagnusp
      pagnus
      pagnusp
       agnus
       agnusp
*/