/*
ID: wsfxk.e1
LANG: C++
TASK: zerosum
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
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 10;

int n;
char l[kN];

void D(int x, int s, int p, bool f) {
  if (x == n) {
    if (s + p == 0) {
      for (int i = 1; i < n; ++i) {
        fout << i << l[i];
      }
      fout << n << endl;
    }
    return;
  }
  l[x] = ' ';
  D(x + 1, s, p * 10 + (f ? -1 : 1) * (x + 1), f);
  l[x] = '+';
  D(x + 1, s + p, x + 1, 0);
  l[x] = '-';
  D(x + 1, s + p, -x - 1, 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  D(1, 0, 1, 0);
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}