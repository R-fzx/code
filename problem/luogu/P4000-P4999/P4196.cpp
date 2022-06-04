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
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 51;
const LD kV = 1e5;

int n;
Pdd a[kN];
vector<Pdd> ans = {{kV, kV}, {-kV, kV}, {-kV, -kV}, {kV, -kV}};

LD Cross(Pdd o, Pdd x, Pdd y) {
  return (x.first - o.first) * (y.second - o.second) - (x.second - o.second) * (y.first - o.first);
}
Pdd P(Pdd x, Pdd y, Pdd i, Pdd j) {
  LD _d = Cross(i, x, j), d = _d / (_d + Cross(i, j, y));
  return {x.first + (y.first - x.first) * d, x.second + (y.second - x.second) * d};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  while (n--) {
    int l;
    cin >> l;
    for (int i = 1; i <= l; ++i) {
      cin >> a[i].first >> a[i].second;
    }
    a[0] = a[l];
    for (int i = 0; i < l; ++i) {
      ans.push_back(ans[0]);
      vector<Pdd> p;
      for (int j = 1; j < ans.size(); ++j) {
        LD c = Cross(a[i], a[i + 1], ans[j - 1]);
        if (c >= 0) {
          p.push_back(ans[j - 1]);
        }
        if (c * Cross(a[i], a[i + 1], ans[j]) < 0) {
          p.push_back(P(ans[j - 1], ans[j], a[i], a[i + 1]));
        }
      }
      ans = p;
    }
  }
  ans.push_back(ans[0]);
  LD s = 0;
  for (int i = 1; i < ans.size(); ++i) {
    s += Cross(ans[0], ans[i - 1], ans[i]);
  }
  cout << fixed << setprecision(3) << s / 2;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}