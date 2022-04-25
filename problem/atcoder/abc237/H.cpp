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

const int kN = 201;

int n, l, p[kN], v[kN], ans;
string s, a[kN * kN];
bool e[kN][kN];

bool F(int x, int c) {
  if (v[x] ^ c) {
    v[x] = c;
    for (int i = 1; i <= l; ++i) {
      if (e[x][i] && (!p[i] || F(p[i], c))) {
        p[i] = x;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s;
  n = s.size(), s = " " + s;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; i + j <= n + 1; ++j) {
      string x = s.substr(i, j), y = x;
      reverse(y.begin(), y.end());
      if (x == y) {
        a[++l] = x;
      }
    }
  }
  sort(a + 1, a + l + 1), l = unique(a + 1, a + l + 1) - a - 1;
  debug("%d\n", l);
  for (int i = 1; i <= l; ++i) {
    debug("%s ", a[i].c_str());
  }
  debug("\n");
  for (int i = 1; i <= l; ++i) {
    for (int j = 1; j <= l; ++j) {
      if ((i ^ j) && a[i].find(a[j]) != string::npos) {
        e[i][j] = 1;
      }
    }
  }
  for (int k = 1; k <= l; ++k) {
    for (int i = 1; i <= l; ++i) {
      for (int j = 1; j <= l; ++j) {
        e[i][j] |= e[i][k] & e[k][j];
      }
    }
  }
  for (int i = 1; i <= l; ++i) {
    ans += F(i, i);
  }
  cout << l - ans;
  return 0;
}
/*
ababb

*/