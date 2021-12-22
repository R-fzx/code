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

const int kN = 301;
const LD kEps = 1e-11, kInf = 1e10;

int n;
Pdd a[kN];
LD ans = kInf;
vector<Pdd> l = {{kInf, kInf}, {-kInf, kInf}, {-kInf, -kInf}, {kInf, -kInf}};

LD Cross(Pdd o, Pdd x, Pdd y) {
  return (x.first - o.first) * (y.second - o.second) - (x.second - o.second) * (y.first - o.first);
}
Pdd P(Pdd x, Pdd y, Pdd i, Pdd j) {
  LD _d = Cross(x, i, y), d = _d / (_d + Cross(x, y, j));
  return {i.first + (j.first - i.first) * d, i.second + (j.second - i.second) * d};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].second;
  }
  for (int i = 2; i <= n; ++i) {
    vector<Pdd> _l;
    l.push_back(l[0]);
    for (int j = 1; j < l.size(); ++j) {
      LD v0 = Cross(a[i - 1], a[i], l[j - 1]);
      if (v0 >= 0) {
        _l.push_back(l[j - 1]);
      }
      if (v0 * Cross(a[i - 1], a[i], l[j]) < 0) {
        _l.push_back(P(a[i - 1], a[i], l[j - 1], l[j]));
      }
    }
    l = _l;
  }
  l.push_back(l[0]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < l.size(); ++j) {
      if (l[j - 1].first <= a[i].first && a[i].first <= l[j].first) {
        ans = min(ans, l[j - 1].second + (l[j].second - l[j - 1].second) / (l[j].first - l[j - 1].first) * (a[i].first - l[j - 1].first) - a[i].second);
      }
    }
  }
  for (int i = 0; i < l.size(); ++i) {
    for (int j = 2; j <= n; ++j) {
      if (a[j - 1].first <= l[i].first && l[i].first <= a[j].first) {
        ans = min(ans, l[i].second - (a[j].second - a[j - 1].second) / (a[j].first - a[j - 1].first) * (l[i].first - a[j - 1].first) - a[j - 1].second);
      }
    }
  }
  cout << fixed << setprecision(3) << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}