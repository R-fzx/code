/*
ID: wsfxk.e1
LANG: C++
TASK: ride
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
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

string a, b;

int C(string x) {
  int s = 1;
  for (char c : x) {
    s = s * (c - 'A' + 1) % 47;
  }
  return s;
}

int main() {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  cout << (C(a) == C(b) ? "GO" : "STAY") << endl;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}