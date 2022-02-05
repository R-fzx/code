/*
ID: wsfxk.e1
LANG: C++
TASK: milk3
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

const int kB = 21;

int a, b, c;
bool v[kB][kB][kB];

void S(int x, int y, int z) {
  if (v[x][y][z]) {
    return;
  }
  v[x][y][z] = 1;
  S(max(b, x + y) - b, min(b, x + y), z), S(min(a, x + y), max(a, x + y) - a, z);
  S(max(c, x + z) - c, y, min(c, x + z)), S(min(a, x + z), y, max(a, x + z) - a);
  S(x, max(c, y + z) - c, min(c, y + z)), S(x, min(b, y + z), max(b, y + z) - b);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("milk3.in");
  ofstream fout("milk3.out");
  fin >> a >> b >> c;
  S(0, 0, c);
  for (int i = 0, j = 0; i <= c; ++i) {
    if (v[0][c - i][i]) {
      if (j) {
        fout << " ";
      }
      fout << i, j = 1;
    }
  }
  fout << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
x->y
max(0, x - b + y) min(b,x+y)
max(b, x + y) - b
*/