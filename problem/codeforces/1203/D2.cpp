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
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;

string a, b;
int ans, pf[kN], pl[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  for (int i = 0, j = 0; i < b.size(); ++i) {
    for (; a[j] != b[i]; ++j) {
    }
    pf[i] = j++;
  }
  for (int i = b.size() - 1, j = a.size() - 1; i >= 0; --i) {
    for (; a[j] != b[i]; --j) {
    }
    pl[i] = j--;
  }
  for (int i = 0; i < b.size(); ++i) {
    debug("%d %d\n", pf[i], pl[i]);
  }
  pl[b.size()] = a.size();
  for (int i = 0; i < b.size(); ++i) {
    ans = max(ans, pl[i + 1] - pf[i] - 1);
  }
  cout << max(ans, pl[0]);
  return 0;
}