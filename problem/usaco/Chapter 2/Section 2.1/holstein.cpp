/*
ID: wsfxk.e1
LANG: C++
TASK: holstein
*/
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
#include <fstream>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

ifstream fin("holstein.in");
ofstream fout("holstein.out");

const int kN = 26, kM = 15;

int n, m, a[kN], b[kM][kN], s[kN], c = kN, ans = 1 << kM + 1;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> a[i];
  }
  fin >> m;
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j <= n; ++j) {
      fin >> b[i][j];
    }
  }
  for (int i = 0; i < (1 << m); ++i) {
    fill(s + 1, s + n + 1, 0);
    int _c = 0;
    for (int j = 0; j < m; ++j) {
      if (i >> j & 1) {
        ++_c;
        for (int k = 1; k <= n; ++k) {
          s[k] += b[j][k];
        }
      }
    }
    bool f = 1;
    for (int j = 1; j <= n; ++j) {
      f &= s[j] >= a[j];
    }
    if (f && c > _c) {
      c = _c, ans = i;
    }
  }
  fout << c;
  for (int i = 0; i < m; ++i) {
    if (ans >> i & 1) {
      fout << " " << i + 1;
    }
  }
  fout << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}