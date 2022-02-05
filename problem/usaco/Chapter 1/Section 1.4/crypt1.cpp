/*
ID: wsfxk.e1
LANG: C++
TASK: crypt1
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

int n, c;
bool v[10];

bool C(int x, int d) {
  bool f = 1;
  for (; x; x /= 10, --d) {
    f &= v[x % 10];
  }
  return f && !d;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("crypt1.in");
  ofstream fout("crypt1.out");
  fin >> n;
  for (int i = 1, x; i <= n; ++i) {
    fin >> x;
    v[x] = 1;
  }
  for (int i = 100; i < 1000; ++i) {
    for (int j = 1; j < 10; ++j) {
      for (int k = 0; k < 10; ++k) {
        c += C(i, 3) && C(j, 1) && C(k, 1) && C(i * j, 3) && C(i * k, 3) && C(i * (j * 10 + k), 4);
      }
    }
  }
  fout << c << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}