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
#include <random>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

random_device rd;
mt19937 rnd(rd());

int rand(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rnd);
}

const int kV = 1e6;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 1; i <= 20; ++i) {
    ofstream data("data/" + to_string(i) + ".in");
    int y = rand(1, kV);
    data << y + rand(0, kV - y) << " " << y << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}