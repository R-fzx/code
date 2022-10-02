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

struct BigInt {
  vector<int> l;

  BigInt() { l.assign(1, 0); }
  BigInt(string s) {
    for (int i = s.size() - 1; i >= 0; --i) {
      l.push_back(s[i] - '0');
    }
  }
  const BigInt operator*(const BigInt &o) const {
    BigInt s;
    s.l.resize(l.size() + o.l.size());
    for (int i = 0; i < l.size(); ++i) {
      for (int j = 0; j < o.l.size(); ++j) {
        s.l[i + j] += l[i] * o.l[j];
      }
    }
    for (int i = 0; i < s.l.size(); ++i) {
      if (s.l[i] > 9) {
        if (i + 1 == s.l.size()) {
          s.l.push_back(0);
        }
        s.l[i + 1] += s.l[i] / 10, s.l[i] %= 10;
      }
    }
    for (; s.l.size() != 1 && !s.l.back(); s.l.pop_back()) {
    }
    return s;
  }
  bool operator<(const BigInt &o) const {
    if (l.size() != o.l.size()) {
      return l.size() < o.l.size();
    }
    for (int i = l.size() - 1; i >= 0; --i) {
      if (l[i] != o.l[i]) {
        return l[i] < o.l[i];
      }
    }
    return 0;
  }
} ans;
ostream &operator<<(ostream &out, const BigInt &x) {
  for (int i = x.l.size() - 1; i >= 0; --i) {
    out << x.l[i];
  }
  return out;
}
int n, k;
string s;

void D(int i, int k, BigInt x) {
  if (!k) {
    if (i == n) {
      // cout << i << ' ' << k << ' ' << x << endl;
      ans = max(ans, x);
    } else {
      // cout << i << ' ' << k << ' ' << x << ' ' << x * BigInt(s.substr(i, n - i)) << endl;
      ans = max(ans, x * BigInt(s.substr(i, n - i)));
    }
    return;
  }
  // cout << i << ' ' << k << ' ' << x << endl;
  for (int j = i + 1; j < n; ++j) {
    // cout << BigInt(s.substr(i, j - i)) << ' ' << BigInt(s.substr(i, j - i)) * x << ':' << endl;
    D(j, k - 1, BigInt(s.substr(i, j - i)) * x);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> s;
  D(0, k, BigInt("1"));
  cout << ans;
  return 0;
}
/*
6 2
356510

107100
*/