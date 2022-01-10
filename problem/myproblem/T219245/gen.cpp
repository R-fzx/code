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
mt19937_64 rnd(rd());

LL rand(LL l, LL r) {
  return uniform_int_distribution<LL>(l, r)(rnd);
}

const LL kY = 1e6, kX = 1e9;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 36; i <= 55; ++i) {
    ofstream data("data/" + to_string(i) + ".in");
    LL y = rand(1, kY);
    data << y + rand(0, kX - y) << " " << y << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}