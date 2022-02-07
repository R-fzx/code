/*
ID: wsfxk.e1
LANG: C++
TASK: subset
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
ifstream fin("subset.in");
ofstream fout("subset.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 40;

int n, s;
LL f[kN][kN * kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  s = n * (n + 1) / 2;
  if (s & 1) {
    fout << 0 << endl;
    return 0;
  }
  s /= 2, f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= s; ++j) {
      f[i][j] = f[i - 1][j] + (j >= i ? f[i - 1][j - i] : 0);
    }
  }
  fout << f[n][s] / 2 << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}