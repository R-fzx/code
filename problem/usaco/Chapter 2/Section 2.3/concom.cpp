/*
ID: wsfxk.e1
LANG: C++
TASK: concom
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
using ULL = unsigned long long;
using Pii = pair<int, int>;

#define FILE_READ
#ifdef FILE_READ
ifstream fin("concom.in");
ofstream fout("concom.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 101;

int m, n, l[kN][kN], h, t, q[kN], r[kN];
bool v[kN];

void R(int x) {
  if (!v[x]) {
    v[x] = 1, q[++t] = x;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    fin >> x >> y >> l[x][y];
    n = max(n, max(x, y));
  }
  for (int i = 1; i <= n; ++i) {
    fill(r + 1, r + n + 1, 0), fill(v + 1, v + n + 1, 0);
    for (h = 1, t = 0, R(i); h <= t; ++h) {
      int x = q[h];
      for (int j = 1; j <= n; ++j) {
        r[j] += l[x][j];
      }
      for (int j = 1; j <= n; ++j) {
        if (r[j] > 50) {
          R(j);
        }
      }
    }
    for (int j = 1; j <= n; ++j) {
      if (i != j && v[j]) {
        fout << i << ' ' << j << endl;
      }
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}