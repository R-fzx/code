/*
ID: wsfxk.e1
LANG: C++
TASK: prefix
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
ifstream fin("prefix.in");
ofstream fout("prefix.out");
#else
#define fin cin
#define fout cout
#endif

const int kN = 2e5 + 1;

vector<string> a;
string s;
bitset<kN> f;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (string _; (fin >> _) && _ != "."; a.push_back(_)) {
  }
  for (string _; fin >> _; s += _) {
  }
  f[0] = 1;
  for (int i = 1; i <= s.size(); ++i) {
    for (string &j : a) {
      if (j.size() <= i && s.substr(i - j.size(), j.size()) == j && f[i - j.size()]) {
        f[i] = 1;
        break;
      }
    }
  }
  int i = s.size();
  for (; !f[i]; --i) {
  }
  fout << i << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}