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

const int kN = 9;

int n, p[kN];
char c[kN];
string a[kN][kN];

int G(char x) { return find(c + 1, c + n + 1, x) - c; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> c[0], --n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[0];
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      if (a[i][j].size() > 2) {
        cout << "ERROR!";
        return 0;
      }
      for (char &x : a[i][j]) {
        x = G(x);
      }
    }
  }
  iota(p + 1, p + n + 1, 0);
  bool f = 0;
  do {
    bool _f = 1;
    for (int i = 1; _f && i <= n; ++i) {
      for (int j = 1; _f && j <= n; ++j) {
        _f &= p[i] + p[j] == (a[i][j].size() == 1 ? p[a[i][j][0]] : p[a[i][j][0]] * n + p[a[i][j][1]]);
      }
    }
    if (_f) {
      f = 1;
      break;
    }
  } while (next_permutation(p + 1, p + n + 1));
  if (f) {
    for (int i = 1; i <= n; ++i) {
      cout << c[i] << '=' << p[i] << ' ';
    }
    cout << '\n' << n;
  } else {
    cout << "ERROR!";
  }
  return 0;
}