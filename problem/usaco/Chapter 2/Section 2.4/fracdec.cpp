/*
ID: wsfxk.e1
LANG: C++
TASK: fracdec
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
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 1e5 + 1;

int n, d, p[kN], c = 1;
bool v[kN];
vector<int> l;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n >> d;
  fout << n / d << ".";
  for (int x = n / d; x; x /= 10, ++c) {
  }
  c += !(n / d);
  if (n % d) {
    n %= d;
    for (int i = 1; n && !p[n]; n %= d, ++i) {
      // fout << i << " " << n << endl;
      p[n] = i, n *= 10, l.push_back(n / d);
    }
    if (p[n]) {
      // fout << p[n] << endl;
      for (int i = 0; i < l.size(); ++i) {
        if (i + 1 == p[n]) {
          fout << "(";
          if (++c == 76) {
            fout << endl;
            c = 0;
          }
        }
        fout << l[i];
        if (++c == 76) {
          fout << endl;
          c = 0;
        }
      }
      fout << ")";
    } else {
      for (int i : l) {
        fout << i;
        if (++c == 76) {
          fout << endl;
          c = 0;
        }
      }
    }
    fout << endl;
  } else {
    fout << "0" << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}