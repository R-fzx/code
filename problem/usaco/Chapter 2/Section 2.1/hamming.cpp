/*
ID: wsfxk.e1
LANG: C++
TASK: hamming
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
ifstream fin("hamming.in");
ofstream fout("hamming.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 256;

int n, b, d;
vector<int> ans;
bitset<kN> l[kN];

int Hamming(int x, int y) { return __builtin_popcount(x ^ y); }
void D(int x, int y, bitset<kN> v) {
  if (x == n) {
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i) {
      if (i) {
        fout << (i % 10 ? ' ' : '\n');
      }
      fout << ans[i];
    }
    fout << '\n';
    exit(0);
  }
  for (int i = 0; i < (1 << b); ++i) {
    if (v[i]) {
      ans[x] = i, D(x + 1, i, v & l[i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n >> b >> d;
  ans.resize(n);
  for (int i = 0; i < (1 << b); ++i) {
    for (int j = 0; j < (1 << b); ++j) {
      if (Hamming(i, j) >= d) {
        l[i].set(j);
      }
    }
  }
  // for (int i = 0; i < (1 << b); ++i) {
  //   for (int j = 0; j < (1 << b); ++j) {
  //     fout << l[i][j];
  //   }
  //   fout << endl;
  // }
  bitset<kN> _ = 0;
  _.flip();
  D(0, -1, _);
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}