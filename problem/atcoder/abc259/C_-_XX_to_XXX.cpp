#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using mL = modint998244353;

string s, t;

bool C() {
  for (int i = 0, j = 0; i < s.size() || j < t.size(); ) {
    if (i == s.size() || j == t.size() || s[i] != t[j]) {
      return 0;
    }
    int pi = i, pj = j;
    for (; i < s.size() && s[i] == s[pi]; ++i) {
    }
    for (; j < t.size() && t[j] == t[pj]; ++j) {
    }
    if (i - pi > j - pj || i - pi == 1 && j - pj != 1) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s >> t;
  cout << (C() ? "Yes" : "No");
  return 0;
}