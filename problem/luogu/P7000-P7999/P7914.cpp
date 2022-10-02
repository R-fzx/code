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

const int kN = 501;
const LL kM = 1e9 + 7;

int n, k;
string s;
LL f[kN][kN], g[kN][kN];
bool v[2][kN][kN];

bool C(int i, char c) { return s[i] == c || s[i] == '?'; }
bool C(int l, int r) {
  if (v[1][l][r] || r - l + 1 > k || r < l) {
    return v[0][l][r];
  }
  v[1][l][r] = 1;
  return v[0][l][r] = count(s.begin() + l, s.begin() + r + 1, '*') + count(s.begin() + l, s.begin() + r + 1, '?') == r - l + 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> s;
  s = " " + s;
  for (int i = 1; i < n; ++i) {
    if (C(i, '(') && C(i + 1, ')')) {
      f[i][i + 1] = 1;
    }
  }
  for (int l = 3; l <= n; ++l) {
    for (int i = 1, j; (j = i + l - 1) <= n; ++i) {
      if (C(i, '(') && C(j, ')')) {
        if (C(i + 1, j - 1)) {
          f[i][j] = 1;
        }
        f[i][j] = (f[i][j] + f[i + 1][j - 1] + g[i + 1][j - 1]) % kM;
        for (int k = i + 1; k < j; ++k) {
          if (C(i + 1, k)) {
            f[i][j] = (f[i][j] + f[k + 1][j - 1] + g[k + 1][j - 1]) % kM;
          }
          if (C(k, j - 1)) {
            f[i][j] = (f[i][j] + f[i + 1][k - 1] + g[i + 1][k - 1]) % kM;
          }
        }
      }
      for (int k = j - 1; k >= i; --k) {
        g[i][j] = (g[i][j] + (f[i][k] + g[i][k]) * f[k + 1][j] % kM) % kM;
        for (int l = 1; l <= ::k && k + l + 1 <= j; ++l) {
          // [i, k] A [k + 1, k + l] S [k + l + 1, j] B
          if (C(k + 1, k + l)) {
            g[i][j] = (g[i][j] + (f[i][k] + g[i][k]) * f[k + l + 1][j] % kM) % kM;
          }
        }
      }
    }
  }
  cout << (f[1][n] + g[1][n]) % kM;
  return 0;
}
/*
(S0)
AS0B -> (f|g)S0f
(A)
(SA)
(AS)
f: (...)
g: (...)...(...)
*/