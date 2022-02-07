/*
ID: wsfxk.e1
LANG: C++
TASK: preface
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
ifstream fin("preface.in");
ofstream fout("preface.out");
#else
#define fin cin
#define fout cout
#endif

const int kD[10][7] = {{}, {1}, {2}, {3}, {1, 1}, {0, 1}, {1, 1}, {2, 1}, {3, 1}, {1, 0, 1}};
const string kT = "IVXLCDM";

int n, s[7];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0, u = 1; k < 4; ++k, u *= 10) {
        if (j + k < 7) {
          s[j + k] += kD[i / u % 10][j];
        }
      }
    }
  }
  for (int i = 0; i < 7; ++i) {
    if (s[i]) {
      fout << kT[i] << " " << s[i] << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}