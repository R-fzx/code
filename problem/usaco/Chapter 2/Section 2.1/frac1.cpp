/*
ID: wsfxk.e1
LANG: C++
TASK: frac1
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
using Pii = pair<int, int>;

ifstream fin("frac1.in");
ofstream fout("frac1.out");

const int kN = 30001;

int n, t;
Pii a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (__gcd(i, j) == 1) {
        a[++t] = {j, i};
      }
    }
  }
  sort(a + 1, a + t + 1, [](Pii x, Pii y) { return x.first * y.second < y.first * x.second; });
  for (int i = 1; i <= t; ++i) {
    fout << a[i].first << "/" << a[i].second << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
x.first/x.second<y.first/y.second
*/