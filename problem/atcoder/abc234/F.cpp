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
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const LL kM = 998244353;
const int kN = 5001, kC = 28;

string s;
LL f[kC][kN];
int n, c[kC];

LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    if (e & 1) {
      s = s * b % kM;
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s;
  n = s.size();
  for (char i : s) {
    ++c[i - 'a' + 1];
  }
  for (int i = 1; i < kC; ++i) {
    cerr << c[i] << " ";
  }
  cerr << endl;
  f[0][0] = 1;
  for (int i = 1; i < kC; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= min(j, c[i]); ++k) {
        f[i][j] = (f[i][j] + f[i - 1][j - k] * P(j - k + 1, k) % kM) % kM;
      }
      cerr << f[i][j] << " ";
    }
    cerr << endl;
  }
  LL s = 0;
  for (int i = 1; i <= n; ++i) {
    s = (s + f[26][i]) % kM;
  }
  // if (s < 0) {
  //   return 1;
  // }
  cout << s;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
a
b
ab
ba
bb
abb
bab
bba
*/