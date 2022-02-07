/*
ID: wsfxk.e1
LANG: C++
TASK: runround
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
ifstream fin("runround.in");
ofstream fout("runround.out");
#else
#define fin cin
#define fout cout
#endif

LL m;

bool C(LL x) {
  vector<Pii> v;
  for (; x; x /= 10) {
    v.emplace_back(x % 10, 0);
  }
  bitset<10> b;
  for (auto &i : v) {
    if (b[i.first] || !i.first) return 0;
    b[i.first] = 1;
  }
  reverse(v.begin(), v.end());
  int i = 0, j = 0;
  do {
    v[i].second = 1, i = (i + v[i].first) % v.size(), ++j;
  } while (!v[i].second);
  return !i && j == v.size();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (fin >> m; !C(++m);) {
  }
  fout << m << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}