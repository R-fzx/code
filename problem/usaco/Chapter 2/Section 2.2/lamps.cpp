/*
ID: wsfxk.e1
LANG: C++
TASK: lamps
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
ifstream fin("lamps.in");
ofstream fout("lamps.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 100;
using A = bitset<kN>;

int n, c;
vector<int> p[2];
A o[4];
vector<A> l[5], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  o[0].flip();
  for (int i = 0; i < kN; ++i) {
    o[2][i] = i & 1;
  }
  o[1] = o[0] ^ o[2];
  for (int i = 0; 3 * i < kN; ++i) {
    o[3][3 * i] = 1;
  }
  for (int i = 0, _c; i < 16; ++i) {
    A x;
    x.flip(), _c = 0;
    for (int j = 0; j < 4; ++j) {
      if (i >> j & 1) {
        x ^= o[j], ++_c;
      }
    }
    l[_c].push_back(x);
  }
  fin >> n >> c;
  for (int i = 1; ~i; --i) {
    for (int x; (fin >> x) && ~x; p[i].push_back(x - 1)) {
    }
  }
  for (int i = c & 1; i <= min(4, c); i += 2) {
    for (A &x : l[i]) {
      bool f = 1;
      for (int j = 0; j < 2; ++j) {
        for (int k : p[j]) {
          f &= x[k] == j;
        }
      }
      if (f) {
        ans.push_back(x);
      }
    }
  }
  sort(ans.begin(), ans.end(), [](A i, A j) {
    for (int k = 0; k < n; ++k) {
      if (i[k] != j[k]) {
        return i[k] < j[k];
      }
    }
    return false;
  });
  int m = unique(ans.begin(), ans.end()) - ans.begin();
  if (m) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        fout << ans[i][j];
      }
      fout << endl;
    }
  } else {
    fout << "IMPOSSIBLE" << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}