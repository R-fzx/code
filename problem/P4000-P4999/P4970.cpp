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

const int kN = 1e5 + 1;

int n, t, o, l, r, v, a[kN], ans;
bool b[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  while (t--) {
    cin >> o >> l;
    if (o == 1) {
      cin >> v;
      a[l] = v - a[l], b[l] = 1;
    } else if (o == 2) {
      cin >> r;
      int m = 0, _ = b[r + 1];
      b[r + 1] = 0;
      for (int i = r; i >= l && !b[i + 1]; --i) {
        if (b[i] || a[i] > a[m]) {
          m = i;
        }
      }
      cout << a[m] << endl;
      b[r + 1] = _, ans += a[m], a[m] = b[m] = 0;
    } else {
      cin >> r >> v;
      for (int i = l; i <= r; ++i) {
        a[i] += v;
      }
    }
  }
  if (ans < 10000) {
    cout << "QAQ";
  } else if (ans < 10000000) {
    cout << "Sakura";
  } else {
    cout << "ice";
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}