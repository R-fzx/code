/*
ID: wsfxk.e1
LANG: C++
TASK: maze1
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
ifstream fin("maze1.in");
ofstream fout("maze1.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 301, kD[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m, p[2][2], d[kN][kN], h = 1, t;
char ch[kN][kN];
Pii q[kN * kN];
string s;

void R(int x, int y, int _d) {
  if (x >= 1 && x <= 2 * n + 1 && y >= 1 && y <= 2 * m + 1 && ch[x][y] == ' ' && d[x][y] > _d) {
    d[x][y] = _d, q[++t] = {x, y};
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> m >> n;
  getline(fin, s);
  for (int i = 1; i <= 2 * n + 1; ++i) {
    getline(fin, s);
    for (; s.size() < 2 * m + 1; s += " ") {
    }
    for (int j = 1; j <= 2 * m + 1; ++j) {
      ch[i][j] = s[j - 1];
      if (ch[i][j] == ' ' && (i == 1 || i == 2 * n + 1 || j == 1 || j == 2 * m + 1)) {
        int o = !!p[0][0];
        p[o][0] = i + (i == 2 * n + 1 ? -1 : i == 1), p[o][1] = j + (j == 2 * m + 1 ? -1 : j == 1);
      }
    }
  }
  fill(&d[0][0], &d[0][0] + kN * kN, 1 << 30);
  for (R(p[0][0], p[0][1], 1), R(p[1][0], p[1][1], 1); h <= t; ++h) {
    int x = q[h].first, y = q[h].second;
    for (int i = 0; i < 4; ++i) {
      int nx = x + kD[i][0], ny = y + kD[i][1];
      if (ch[nx][ny] == ' ') {
        R(nx + kD[i][0], ny + kD[i][1], d[x][y] + 1);
      }
    }
  }
  int s = 0;
  for (int i = 1; i <= 2 * n + 1; ++i) {
    for (int j = 1; j <= 2 * m + 1; ++j) {
      if (d[i][j] != 1 << 30) {
        s = max(s, d[i][j]);
      }
    }
  }
  fout << s << "\n";
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}