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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 5e5 + 1;
const LL kM = 1e9 + 7;

int n, q, b[kN], l, r;
LL x;

LL highbit(LL x) {
  int i = 62;
  for (; i >= 0 && !(x >> i & 1); --i) {
  }
  return 1LL << i;
}
LL lowbit(LL x) { return x & -x; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    b[i] = c - '0';
  }
  while (q--) {
    cin >> l >> r >> x;
    for (int i = l; i <= r; ++i) {
      if (b[i]) {
        x += highbit(x);
      } else {
        x += lowbit(x);
      }
    }
    cout << x % kM << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}