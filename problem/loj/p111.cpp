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
#include <random>
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

const int kN = 1e6 + 1;

int n, rk[kN << 1], ork[kN << 1], sa[kN], c[kN], d[kN], rd[kN];
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s, n = s.size();
  for (int i = 1; i <= n; ++i) {
    ++c[rk[i] = s[i - 1]];
  }
  for (int i = 1; i <= 256; ++i) {
    c[i] += c[i - 1];
  }
  for (int i = n; i >= 1; --i) {
    sa[c[rk[i]]--] = i;
  }
  for (int l = 1, p = 256; l < n; l <<= 1) {
    int j = 0;
    for (int i = n; i > n - l; --i) {
      d[++j] = i;
    }
    for (int i = 1; i <= n; ++i) {
      if (sa[i] > l) {
        d[++j] = sa[i] - l;
      }
    }
    fill(c, c + p + 1, 0);
    for (int i = 1; i <= n; ++i) {
      ++c[rd[i] = rk[d[i]]];
    }
    for (int i = 1; i <= p; ++i) {
      c[i] += c[i - 1];
    }
    for (int i = n; i >= 1; --i) {
      sa[c[rd[i]]--] = d[i];
    }
    copy_n(rk + 1, n, ork + 1), p = 0;
    for (int i = 1, x = 0, y; i <= n; ++i) {
      y = x, x = sa[i], rk[x] = (ork[x] == ork[y] && ork[x + l] == ork[y + l] ? p : ++p);
    }
    if (p == n) {
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << sa[i] << ' ';
  }
  return 0;
}