/*
ID: wsfxk.e1
LANG: C++
TASK: palsquare
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

int b;

string T(int x) {
  string s;
  for (; x; x /= b) {
    s.push_back(x % b >= 10 ? x % b - 10 + 'A' : x % b + '0'); 
  }
  reverse(s.begin(), s.end());
  return s;
}
bool P(string s) {
  string _ = s;
  reverse(_.begin(), _.end());
  return _ == s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");
  fin >> b;
  for (int i = 1; i <= 300; ++i) {
    if (P(T(i * i))) {
      fout << T(i) << " " << T(i * i) << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}