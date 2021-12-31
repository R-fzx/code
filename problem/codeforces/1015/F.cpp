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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const LL kN = 201, kM = 1e9 + 7;

int n, l, ne[kN][2];
string s;
LL f[kN][kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  l = s.size(), n <<= 1;
  for (int i = 0; i < l; ++i) {
    s[i] = s[i] == ')';
    for (int j = 0; j <= i; ++j) {
      for (int o = 0; o <= 1; ++o) {
        if (s[j] == o && s.substr(0, j) == s.substr(i - j, j)) {
          ne[i][o] = j + 1;
        }
      }
    }
  }
  ne[l][0] = ne[l][1] = l, f[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= l; ++j) {
      for (int k = 0; k <= i; ++k) {
        for (int o = 0; o <= 1; ++o) {
          int _k = k + (o ? -1 : 1);
          if (_k >= 0) {
            f[i + 1][ne[j][o]][_k] = (f[i + 1][ne[j][o]][_k] + f[i][j][k]) % kM;
          }
        }
      }
    }
  }
  cout << f[n][l][0];
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}