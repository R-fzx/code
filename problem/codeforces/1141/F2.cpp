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
// #define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1501;

int n, a[kN], s[kN];
vector<Pii> b, l, _l;

int S(Pii x) { return s[x.second] - s[x.first - 1]; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    for (int j = 1; j <= i; ++j) {
      b.emplace_back(j, i);
    }
  }
  sort(b.begin(), b.end(), [](Pii x, Pii y) {
    return S(x) < S(y) || S(x) == S(y) && x.second < y.second;
  });
  for (int i = 0, j = 0; i < b.size(); i = j) {
    for (; j < b.size() && S(b[j]) == S(b[i]); ++j) {
    }
    debug("%d %d\n", i, j);
    _l.clear();
    for (int pr = 0, k = i; k < j; ++k) {
      if (b[k].first > pr) {
        pr = b[k].second, _l.push_back(b[k]);
      }
    }
    if (_l.size() > l.size()) {
      l = _l;
    }
  }
  cout << l.size() << endl;
  for (auto x : l) {
    cout << x.first << ' ' << x.second << endl;
  }
  return 0;
}
/*

*/