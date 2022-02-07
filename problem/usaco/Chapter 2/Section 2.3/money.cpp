/*
ID: wsfxk.e1
LANG: C++
TASK: money
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
using ULL = unsigned long long;
using Pii = pair<int, int>;

#define FILE_READ
#ifdef FILE_READ
ifstream fin("money.in");
ofstream fout("money.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 10001, kV = 26;

int v, n;
LL f[kN][kV], a[kV];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> v >> n;
  for (int i = 1; i <= v; ++i) {
    fin >> a[i];
  }
  sort(a + 1, a + v + 1);
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= v; ++j) {
      if (a[j] <= i) {
        for (int k = 0; k <= j; ++k) {
          f[i][j] += f[i - a[j]][k];
        }
      }
    }
  }
  LL s = 0;
  for (int i = 1; i <= v; ++i) {
    s += f[n][i];
  }
  fout << s << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}