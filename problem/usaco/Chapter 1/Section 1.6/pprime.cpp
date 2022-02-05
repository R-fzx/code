/*
ID: wsfxk.e1
LANG: C++
TASK: pprime
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

ifstream fin("pprime.in");
ofstream fout("pprime.out");

int l, r;

bool P(int x) {
  bool f = x != 1;
  for (int i = 2; i * i <= x; ++i) {
    f &= x % i != 0;
  }
  return f;
}
void C(vector<int> y) {
  int x = 0;
  for (int i : y) {
    x = x * 10 + i;
  }
  if (x >= l && x <= r && P(x)) {
    fout << x << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> l >> r;
  for (int i = 1; i <= 9; i += 2) {
    C({i});
  }
  for (int i = 1; i <= 9; i += 2) {
    C({i, i});
  }
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; ++j) {
      C({i, j, i});
    }
  }
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; ++j) {
      C({i, j, j, i});
    }
  }
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; ++j) {
      for (int k = 0; k <= 9; ++k) {
        C({i, j, k, j, i});
      }
    }
  }
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; ++j) {
      for (int k = 0; k <= 9; ++k) {
        C({i, j, k, k, j, i});
      }
    }
  }
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; ++j) {
      for (int k = 0; k <= 9; ++k) {
        for (int u = 0; u <= 9; ++u) {
          C({i, j, k, u, k, j, i});
        }
      }
    }
  }
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; ++j) {
      for (int k = 0; k <= 9; ++k) {
        for (int u = 0; u <= 9; ++u) {
          C({i, j, k, u, u, k, j, i});
        }
      }
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}