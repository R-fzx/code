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

const int kN = 2.5e4 + 1, kM = 4e6 + 1;

struct E {
  int n[2], l, r;
} e[kM];
int n, m, c;
string s;

void I(int l, int r) {
  int x = 1;
  for (int i = l; i <= r; ++i) {
    int &y = e[x].n[s[i] - '0'];
    if (!y) {
      y = ++c;
    }
    x = y;
  }
  e[x].l = l, e[x].r = r;
}
void D(int x) {
  
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  s = " " + s, m = sqrt(n) + 1;
  for (int l = 1; l <= m; ++l) {
    for (int i = 1, j; (j = i + l - 1) <= n; ++i) {
      I(i, j);
    }
  }

  return 0;
}