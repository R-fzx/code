/*
ID: wsfxk.e1
LANG: C++
TASK: sort3
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
ifstream fin("sort3.in");
ofstream fout("sort3.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 1001;

int n, a[kN], b[kN], ans[3];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    fin >> a[i];
  }
  copy(a + 1, a + n + 1, b + 1), sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i) {
    ans[0] += a[i] != b[i] && b[i] != 3, ans[1] += a[i] == 1 && b[i] == 2, ans[2] += a[i] == 2 && b[i] == 1;
  }
  fout << ans[0] - min(ans[1], ans[2]) << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}