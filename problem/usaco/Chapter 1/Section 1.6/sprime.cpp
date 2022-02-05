/*
ID: wsfxk.e1
LANG: C++
TASK: sprime
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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

const int kD[2][4] = {{2, 3, 5, 7}, {1, 3, 7, 9}};

int n;

bool P(int x) {
  bool f = 1;
  for (int i = 2; i * i <= x; ++i) {
    f &= x % i != 0;
  }
  return f;
}
void D(int x, int s) {
  if (x > n) {
    fout << s << endl;
    return;
  }
  for (int i = 0; i < 4; ++i) {
    int y = s * 10 + kD[x > 1][i];
    if (P(y)) {
      D(x + 1, y);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  D(1, 0);
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}