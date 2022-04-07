#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1001, kH = 10;
const LL kM = 998244353;

int n;
string s;
LL f[kN][1 << kH][kH + 1];

void U(int i, int j, int k) {
  f[i + 1][j][k] = (f[i + 1][j][k] + f[i][j][k]) % kM;
  int x = s[i + 1] - 'A';
  if (k == x) {
    f[i + 1][j][k] = (f[i + 1][j][k] + f[i][j][k]) % kM;
  } else if (j >> x & 1 ^ 1) {
    f[i + 1][j | 1 << x][x] = (f[i + 1][j | 1 << x][x] + f[i][j][k]) % kM;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  s = "#" + s;
  f[0][0][10] = 1;
  for (int i = 0; i < n; ++i) {
    U(i, 0, 10);
    for (int j = 1; j < 1024; ++j) {
      for (int k = 0; k < 10; ++k) {
        if (j >> k & 1) {
          U(i, j, k);
        }
      }
    }
  }
  LL s = 0;
  for (int i = 1; i < 1024; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (i >> j & 1) {
        s = (s + f[n][i][j]) % kM;
      }
    }
  }
  cout << s;
  return 0;
}
/*

f[i][j][k]:前i个字符，状态为j，最后一串字符为k的方案数
*/