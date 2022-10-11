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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kV = 1e6 + 1;

int t;
bool v[kV];
vector<int> lp;
vector<Pll> lb;
LL a, b, k, c;

LL G(LL a, LL b) { return b ? G(b, a % b) : a; }
LL M(LL x, LL y, LL p) {
  x %= p, y %= p;
  LL s = 0;
  for (; y; y >>= 1, x = x * 2 % p) {
    if (y & 1) {
      s = (s + x) % p;
    }
  }
  return s;
}
LL P(LL b, LL e, LL p) {
  b %= p;
  LL s = 1;
  for (; e; e >>= 1, b = M(b, b, p)) {
    if (e & 1) {
      s = M(s, b, p);
    }
  }
  return s;
}

int main() {
  RF("kubi");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 2; i < kV; ++i) {
    if (!v[i]) {
      lp.push_back(i);
      for (LL j = 1LL * i * i; j < kV; j += i) {
        v[j] = 1;
      }
    }
  }
  for (cin >> t; t--;) {
    cin >> a >> b >> k;
    LL g = G(a, b), x;
    a /= g, b /= g;
    c = 0;
    for (; (g = G(b, k)) > 1; ++c, b /= g) {
    }
    LL pb = b;
    if (b > 1) {
      x = b;
      for (int i : lp) {
        if (x % i == 0) {
          pb = pb / i * (i - 1);
          for (; x % i == 0; x /= i) {
          }
        }
      }
      if (x > 1) {
        pb = pb / x * (x - 1);
      }
      x = pb;
      // cout << pb << endl;
      lb.clear();
      for (int i : lp) {
        if (x % i == 0) {
          int c = 0;
          for (; x % i == 0; x /= i, ++c) {
          }
          lb.emplace_back(i, c);
        }
      }
      // for (auto &i : lb) {
      //   cout << i.first << ' ' << i.second << '\n';
      //   // for (; i.second && P(k, pb / i.first, b) == 1; --i.second, pb /= i.first) {
      //   // }
      // }
      // cout << x << '\n';
      if (x > 1) {
        lb.emplace_back(x, 1);
      }
      // for (auto &i : lb) {
      //   cout << i.first << ' ' << i.second << '\n';
      //   // for (; i.second && P(k, pb / i.first, b) == 1; --i.second, pb /= i.first) {
      //   // }
      // }
      reverse(lb.begin(), lb.end());
      for (auto &i : lb) {
        // cout << i.first << ' ' << i.second << '\n';
        // cout << pb /*<< ' ' << P(k, pb / i.first, b)*/ << endl;
        for (; i.second && P(k, pb / i.first, b) == 1; --i.second, pb /= i.first) {
        }
      }
      cout << c << ' ' << pb << '\n';
    } else {
      cout << c << " 0\n";
    }
  }
  return 0;
}