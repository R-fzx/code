/*
ID: wsfxk.e1
LANG: C++
TASK: dualpal
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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

int n, s, c;

string T(int x, int b) {
  string s;
  for (; x; x /= b) {
    s.push_back(x % b + '0');
  }
  return s;
}
bool P(string x) {
  string y = x;
  reverse(y.begin(), y.end());
  return x == y;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");
  fin >> n >> s;
  while (++s, n) {
    c = 0;
    for (int i = 2; i <= 10; ++i) {
      c += P(T(s, i));
    }
    if (c > 1) {
      fout << s << endl;
      --n;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}