#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
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
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

LL t[10][10];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  t[1][1] = 0;
  t[1][2] = 2;
  t[1][3] = 4;
  t[1][4] = 6;
  t[1][5] = 8;
  t[1][6] = 10;
  t[1][7] = 12;
  t[1][8] = 14;
  t[2][1] = 2;
  t[2][2] = 12;
  t[2][3] = 30;
  t[2][4] = 56;
  t[2][5] = 90;
  t[2][6] = 132;
  t[2][7] = 182;
  t[2][8] = 240;
  t[3][1] = 4;
  t[3][2] = 30;
  t[3][3] = 104;
  t[3][4] = 286;
  t[3][5] = 700;
  t[3][6] = 1598;
  t[3][7] = 3488;
  t[3][8] = 7390;
  t[4][1] = 6;
  t[4][2] = 56;
  t[4][3] = 286;
  t[4][4] = 1228;
  t[4][5] = 4862;
  t[4][6] = 18368;
  t[4][7] = 67206;
  t[4][8] = 240180;
  t[5][1] = 8;
  t[5][2] = 90;
  t[5][3] = 700;
  t[5][4] = 4862;
  t[5][5] = 32000;
  t[5][6] = 204294;
  t[5][7] = 1274660;
  t[5][8] = 7807790;
  t[6][1] = 10;
  t[6][2] = 132;
  t[6][3] = 1598;
  t[6][4] = 18368;
  t[6][5] = 204294;
  t[6][6] = 2228788;
  t[6][7] = 23896710;
  t[6][8] = 252488208;
  t[7][1] = 12;
  t[7][2] = 182;
  t[7][3] = 3488;
  t[7][4] = 67206;
  t[7][5] = 1274660;
  t[7][6] = 23896710;
  t[7][7] = 441524056;
  t[7][8] = 8056291934;
  int n, m;
  cin >> n >> m;
  cout << t[n][m];
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}