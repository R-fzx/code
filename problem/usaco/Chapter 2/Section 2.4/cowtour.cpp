/*
ID: wsfxk.e1
LANG: C++
TASK: cowtour
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

// #define FILE_READ
#ifdef FILE_READ
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 151;

int n;
Pii a[kN];
bool l[kN][kN];
double d[kN][kN];

double D(double x, double y) {
  return sqrt(x * x + y * y);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch;
      fin >> ch;
      l[i][j] = ch == '1', d[i][j] = (l[i][j] ? D(a[i].first - a[j].first, a[i].second - a[j].second) : 1e18);
    }
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}