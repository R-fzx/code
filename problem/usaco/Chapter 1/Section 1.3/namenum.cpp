/*
ID: wsfxk.e1
LANG: C++
TASK: namenum
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

const int kD[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};

string a;

string S(string s) {
  for (char &c : s) {
    c = kD[c - 'A'] + '0';
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("namenum.in"), fdi("dict.txt");
  ofstream fout("namenum.out");
  fin >> a;
  bool f = 0;
  for (string s; fdi >> s; ) {
    if (S(s) == a) {
      fout << s << endl;
      f = 1;
    }
  }
  if (!f) {
    fout << "NONE" << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}