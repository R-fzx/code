/*
ID: wsfxk.e1
LANG: C++
TASK: ttwo
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
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 11, kD[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

char a[kN][kN];
bool v[kN][kN][4][kN][kN][4];
int p[2][2], d[2];

void M(int o) {
  int nx = p[o][0] + kD[d[o]][0], ny = p[o][1] + kD[d[o]][1];
  if (nx < 1 || nx >= kN || ny < 1 || ny >= kN || a[nx][ny] == '*') {
    d[o] = (d[o] + 1) % 4;
  } else {
    p[o][0] = nx, p[o][1] = ny;
  }
}
int S() {
  int c = 0;
  for (; p[0][0] != p[1][0] || p[0][1] != p[1][1];) {
    if (v[p[0][0]][p[0][1]][d[0]][p[1][0]][p[1][1]][d[1]]) {
      return 0;
    }
    v[p[0][0]][p[0][1]][d[0]][p[1][0]][p[1][1]][d[1]] = 1, ++c, M(0), M(1);
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 1; i < kN; ++i) {
    for (int j = 1; j < kN; ++j) {
      fin >> a[i][j];
      if (a[i][j] == 'F') {
        p[0][0] = i, p[0][1] = j;
      } else if (a[i][j] == 'C') {
        p[1][0] = i, p[1][1] = j;
      }
    }
  }
  fout << S() << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}