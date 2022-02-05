/*
ID: wsfxk.e1
LANG: C++
TASK: combo
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

int n, a[2][3], c[3], s;

bool C(int o) {
  bool f = 1;
  for (int i = 0; i < 3; ++i) {
    bool _f = 0;
    for (int j = -2; j <= 2; ++j) {
      _f |= (a[o][i] + j + n) % n == c[i];
    }
    f &= _f;
  }
  return f;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("combo.in");
  ofstream fout("combo.out");
  fin >> n;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      fin >> a[i][j];
      --a[i][j];
    }
  }
  for (c[0] = 0; c[0] < n; ++c[0]) {
    for (c[1] = 0; c[1] < n; ++c[1]) {
      for (c[2] = 0; c[2] < n; ++c[2]) {
        s += C(0) || C(1);
      }
    }
  }
  fout << s << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}