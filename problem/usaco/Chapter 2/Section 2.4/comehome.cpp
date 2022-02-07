/*
ID: wsfxk.e1
LANG: C++
TASK: comehome
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
using ULL = unsigned long long;
using Pii = pair<int, int>;

#define FILE_READ
#ifdef FILE_READ
ifstream fin("comehome.in");
ofstream fout("comehome.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 52;

int n, m, l[kN][kN];
char x, y;

int Encode(char ch) { return ch >= 'a' ? ch - 'a' : ch - 'A' + 26; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fill(&l[0][0], &l[0][0] + kN * kN, 1e9);
  fin >> m;
  for (int i = 1, d; i <= m; ++i) {
    fin >> x >> y >> d;
    l[Encode(x)][Encode(y)] = l[Encode(y)][Encode(x)] = min(l[Encode(x)][Encode(y)], d);
  }
  for (int k = 0; k < kN; ++k) {
    for (int i = 0; i < kN; ++i) {
      for (int j = 0; j < kN; ++j) {
        l[i][j] = min(l[i][j], l[i][k] + l[k][j]);
      }
    }
  }
  int ans = Encode('A');
  for (int i = ans + 1; i < kN - 1; ++i) {
    if (l[i][kN - 1] < l[ans][kN - 1]) {
      ans = i;
    }
  }
  fout << (char)(ans - 26 + 'A') << " " << l[ans][kN - 1] << '\n';
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}