/*
ID: wsfxk.e1
LANG: C++
TASK: agrinet
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
ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 101;

int n, l[kN][kN], d[kN], ans;
bool v[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      fin >> l[i][j];
    }
    d[i] = (i == 1 ? 0 : 1e9);
  }
  d[0] = 1e9;
  for (int _ = 1; _ <= n; ++_) {
    // for (int j = 1; j <= n; ++j) {
    //   cout << d[j] << " ";
    // }
    // cout << endl;
    int x = 0;
    for (int j = 1; j <= n; ++j) {
      if (!v[j] && d[j] < d[x]) {
        x = j;
      }
    }
    ans += d[x], v[x] = 1;
    for (int j = 1; j <= n; ++j) {
      if (!v[j]) {
        d[j] = min(d[j], l[x][j]);
      }
    }
  }
  fout << ans << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}