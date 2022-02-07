/*
ID: wsfxk.e1
LANG: C++
TASK: nocows
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
ifstream fin("nocows.in");
ofstream fout("nocows.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 200, kK = 100, kM = 9901;

int n, k, f[kN][kK];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    f[1][i] = 1;
  }
  for (int h = 1; h <= k; ++h) {
    for (int i = 3; i <= n; i += 2) {
      for (int j = 1; j <= i - 2; j += 2) {
        f[i][h] = (f[i][h] + f[j][h - 1] * f[i - j - 1][h - 1] % kM) % kM;
      }
    }
  }
  fout << (f[n][k] - f[n][k - 1] + kM) % kM << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}