/*
ID: wsfxk.e1
LANG: C++
TASK: gift1
*/
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

const int kN = 11;

int n, a[kN];
string s[kN], _s;

int &G() { return a[find(s + 1, s + n + 1, _s) - s]; }

int main() {
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (int i = 1, c, l; i <= n; ++i) {
    cin >> _s >> c >> l;
    if (l) {
      G() -= c / l * l;
      for (int j = 1; j <= l; ++j) {
        cin >> _s;
        G() += c / l;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << s[i] << " " << a[i] << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}